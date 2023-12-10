/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maix <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:02:12 by maix              #+#    #+#             */
/*   Updated: 2023/12/10 20:48:09 by maix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hash/sip/sip_utils.h"
#include "me/hash/sip.h"

static t_usize _rotl(const t_usize value, t_u8 shift)
{
	if ((shift &= sizeof(value) * 8 - 1) == 0)
		return value;
	return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}

static t_usize _rotr(const t_usize value, t_u8 shift)
{
	if ((shift &= sizeof(value) * 8 - 1) == 0)
		return value;
	return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}

void compress(t_sip_state *state)
{
	state->v0 = state->v0 + state->v1;
	state->v1 = _rotl(state->v1, 13);
	state->v1 ^= state->v0;
	state->v0 = _rotl(state->v0, 32);
	state->v2 = state->v2 + state->v3;
	state->v3 = _rotl(state->v3, 16);
	state->v3 ^= state->v2;
	state->v0 = state->v0 + state->v3;
	state->v3 = _rotl(state->v3, 21);
	state->v3 ^= state->v0;
	state->v2 = state->v2 + state->v1;
	state->v1 = _rotl(state->v1, 17);
	state->v1 ^= state->v2;
	state->v2 = _rotl(state->v2, 32);
}

t_sip_state create_state_with_key(t_u64 k0, t_u64 k1)
{
	t_sip_state state = (t_sip_state){.v0 = 0, .v1 = 0, .v2 = 0, .v3 = 0};
	state.v0 = k0 ^ 0x736f6d6570736575;
	state.v1 = k1 ^ 0x646f72616e646f6d;
	state.v2 = k0 ^ 0x6c7967656e657261;
	state.v3 = k1 ^ 0x7465646279746573;
	return state;
}

static t_usize me_min(t_usize lhs, t_usize rhs)
{
	if (lhs < rhs)
		return lhs;
	return rhs;
}

static t_u64 u8to64_le(t_u8 *msg, t_usize start, t_usize len)
{
	t_usize i;
	t_usize out;
	t_u64	temp_val;
	if (i + 3 < len)
	{
		temp_val = (t_u64)(msg[start + i]);
		temp_val |= (t_u64)(msg[start + i + 1]) << (8 * 1);
		temp_val |= (t_u64)(msg[start + i + 2]) << (8 * 2);
		temp_val |= (t_u64)(msg[start + i + 3]) << (8 * 3);
		out = temp_val;
		i += 4;
	}
	if (i + 1 < len)
	{
		temp_val = (t_u64)(msg[start + i + 1]) << (8 * 1);
		temp_val |= (t_u64)(msg[start + i]);
		out |= temp_val << (i * 8);
		i += 2;
	}
	if (i < len)
	{
		out |= (t_u64)(msg[start + i]) << (i * 8);
		i += 1;
	}
	return out;
}

static t_usize handle_remaining(t_sip13 *self, t_u8 *msg, t_usize count,
						 bool *exit_early)
{
	t_usize needed;

	needed = 0;
	*exit_early = false;

	if (self->ntail != 0)
	{
		needed = 8 - self->ntail;
		self->tail |= u8to64_le(msg, 0, me_min(count, needed))
					  << (8 * self->ntail);
		if (count < needed)
		{
			self->ntail += count;
			*exit_early = true;
			return needed;
		}
		else
		{
			self->state.v3 ^= self->tail;
			compress(&self->state);
			self->state.v0 ^= self->tail;
			self->ntail = 0;
		}
	}
	return needed;
}

void sip13_write_bytes(t_sip13 *self, t_u8 *msg, t_usize count)
{

	bool	exit_early;
	t_usize needed;
	t_usize left;
	t_usize i;
	t_u64	mi;

	self->length += count;
	needed = handle_remaining(self, msg, count, &exit_early);
	if (exit_early)
		return;
	count = count - needed;
	left = count & 0x7;
	i = needed;
	while (i < count - left)
	{
		mi = (t_u64)(msg[i]);
		mi |= (t_u64)(msg[i + 1]) << (8 * 1);
		mi |= (t_u64)(msg[i + 2]) << (8 * 2);
		mi |= (t_u64)(msg[i + 3]) << (8 * 3);
		self->state.v3 ^= mi;
		compress(&self->state);
		self->state.v0 ^= mi;
		i += 8;
	}
	self->tail = u8to64_le(msg, i, left);
	self->ntail = left;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sip.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maix <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:33:46 by maix              #+#    #+#             */
/*   Updated: 2023/12/10 20:03:30 by maix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIP_H
#define SIP_H
#include "me/hash/hasher.h"
#include "me/types.h"

typedef struct s_sip_state
{
	t_u64 v0;
	t_u64 v2;
	t_u64 v1;
	t_u64 v3;
} t_sip_state;

typedef struct s_sip13
{
	t_u64		k0;
	t_u64		k1;
	t_usize		length;
	t_u64		tail;
	t_usize		ntail;
	t_sip_state state;
} t_sip13;

// This also need to drop the inner hasher
t_u64 sip13_finish(t_sip13 *hasher);

t_hasher hasher_sip13_new(void);


#endif

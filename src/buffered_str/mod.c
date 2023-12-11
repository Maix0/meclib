/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:52:12 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/11 18:43:31 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/buffered_str/buf_str.h"
#include "me/mem/mem_alloc.h"
#include "me/string/str_l_cat.h"
#include "me/string/str_l_copy.h"
#include "me/string/str_len.h"
#include "me/types.h"
#include <stdlib.h>

bool	push_str_buffer(t_buffer_str *buf, t_const_str to_push)
{
	t_usize	to_push_len;
	t_str	temp_buffer;
	t_usize	new_capacity;

	if (buf == NULL || to_push == NULL)
		return (true);
	to_push_len = str_len(to_push);
	while (buf->len + to_push_len + 2 > buf->capacity)
	{
		new_capacity = (buf->capacity * 3) / 2 + 1;
		temp_buffer = mem_alloc(new_capacity);
		if (temp_buffer == NULL)
			return (true);
		str_l_copy(temp_buffer, buf->buf, new_capacity);
		free(buf->buf);
		buf->buf = temp_buffer;
		buf->capacity = new_capacity;
	}
	buf->len += to_push_len;
	str_l_cat(buf->buf, to_push, buf->capacity);
	return (false);
}

t_buffer_str	alloc_new_buffer(t_usize capacity)
{
	t_buffer_str	out;
	t_str			buf;

	buf = mem_alloc(sizeof(char) * capacity);
	if (buf == NULL)
	{
		out.buf = NULL;
		out.capacity = 0;
		out.len = 0;
		return (out);
	}
	out.buf = buf;
	out.capacity = capacity;
	out.len = 0;
	return (out);
}

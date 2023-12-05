/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:16:02 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/06 11:40:08 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/memchr.h"

void	*me_memchr(void *buf, t_i32 find, t_usize count)
{
	t_usize	i;
	t_u8	value;
	t_u8	*buf_bytes;

	i = 0;
	buf_bytes = (t_u8 *)buf;
	value = (t_u8)find;
	while (i < count)
	{
		if (buf_bytes[i] == value)
			return ((void *)&buf_bytes[i]);
		i++;
	}
	return (NULL);
}

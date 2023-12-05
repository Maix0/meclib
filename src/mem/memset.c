/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:16:02 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/06 14:35:25 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/memset.h"

void	*me_memset(void *buf, t_i32 fill_by, t_usize count)
{
	t_usize	i;
	t_u8	value;
	t_u8	*buf_bytes;

	i = 0;
	buf_bytes = (t_u8 *)buf;
	value = (t_u8)fill_by;
	while (i < count)
	{
		buf_bytes[i] = value;
		i++;
	}
	return (buf);
}

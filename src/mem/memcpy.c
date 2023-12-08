/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:16:02 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/08 16:26:04 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/memcpy.h"

void *me_memcpy(void *destination, const void *source, t_usize count)
{
	t_usize		i;
	t_u8	   *dst;
	const t_u8 *src;

	i = 0;
	dst = (t_u8 *)destination;
	src = (const t_u8 *)source;
	if (dst == src)
		return (destination);
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (destination);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:11 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/06 11:59:50 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/bzero.h"

void	me_bzero(void *buf, t_usize count)
{
	t_u8	*buffer;
	t_usize	index;

	index = 0;
	buffer = (t_u8 *)buf;
	while (index < count)
	{
		buffer[index] = 0;
		index++;
	}
}

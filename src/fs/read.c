/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:21:19 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/03 15:56:19 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/fs/read.h"
#include <unistd.h>

t_u64	me_read(t_file fd, t_u8 *buffer, t_i64 buffer_max, t_bool *eof_out)
{
	ssize_t	out;

	out = read(fd, buffer, buffer_max);
	if (out == 0 && buffer_max != 0 && eof_out != NULL)
		*eof_out = TRUE;
	return (out);
}

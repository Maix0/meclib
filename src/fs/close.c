/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:56:56 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/04 16:08:10 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/fs/close.h"
#include "ft/std.h"
#include <unistd.h>

t_bool	me_close(t_file file, t_i32 *error)
{
	t_i32	res;
	t_bool	out;

	res = close(file);
	out = res != 0;
	if (res && error != NULL)
		*error = res;
	return (res);
}

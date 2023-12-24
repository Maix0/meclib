/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:29:38 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/24 18:58:14 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/fs/open.h"
#include <fcntl.h>

bool	me_open(t_const_str path, bool read, bool write, t_file *file_out)
{
	t_file	out;
	int		flags;

	flags = 0;
	if (read && write)
		flags = O_RDWR;
	else if (read)
		flags = O_RDONLY;
	else if (write)
		flags = O_WRONLY;
	out = open(path, flags);
	if (out < 0)
		return (true);
	*file_out = out;
	return (false);
}

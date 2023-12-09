/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:29:38 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/15 12:46:01 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/fs/open.h"
#include <fcntl.h>

t_bool	me_open(t_str path, t_bool read, t_bool write, t_file *file_out)
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
		return (TRUE);
	*file_out = out;
	return (FALSE);
}

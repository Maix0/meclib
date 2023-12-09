/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:39:08 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/08 13:33:14 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/fs/putstr_fd.h"
#include "ft/log/log.h"

void	me_print(t_str msg)
{
	me_putstr_fd(msg, STDOUT);
}

void	me_println(t_str msg)
{
	me_putstr_fd(msg, STDOUT);
	me_putstr_fd("\n", STDOUT);
}

void	me_eprint(t_str msg)
{
	me_putstr_fd(msg, STDERR);
}

void	me_eprintln(t_str msg)
{
	me_putstr_fd(msg, STDERR);
	me_putstr_fd("\n", STDERR);
}

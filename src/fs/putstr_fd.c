/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 04:42:45 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/10 16:23:44 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/fs/putstr_fd.h"
#include "ft/fs/write.h"
#include "ft/string/strlen.h"

void	me_putstr_fd(t_str str, t_file file)
{
	if (str == NULL)
		return ;
	me_write(file, (t_u8 *)str, me_strlen(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:07:41 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 14:52:13 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/string/strlen.h"

t_usize	str_len(t_const_str str)
{
	t_usize	out;

	out = 0;
	while (str[out])
		out++;
	return (out);
}

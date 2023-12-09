/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:48 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 14:47:50 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/string/str_clone.h"
#include "ft/string/str_l_copy.h"
#include "ft/string/strlen.h"
#include <stdlib.h>

t_str	str_clone(t_const_str source)
{
	t_str	res;
	t_usize	len;

	len = str_len(source) + 1;
	res = mem_alloc(sizeof(unsigned char) * len);
	if (res == NULL)
		return (NULL);
	str_l_copy(res, source, len);
	return (res);
}

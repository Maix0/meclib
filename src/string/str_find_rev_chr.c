/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find_rev_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:13 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 14:47:47 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/string/str_find_rev_chr.h"
#include "me/string/str_len.h"

char	*str_find_rev_chr(t_const_str str, char chr)
{
	t_usize	index;

	index = str_len((t_str)str);
	while (index >= 0)
	{
		if (str[index] == chr)
			return ((char *)&str[index]);
		index--;
	}
	return (NULL);
}

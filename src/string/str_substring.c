/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_str_substringing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:42:55 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 14:57:43 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem/calloc.h"
#include "ft/string/str_l_copy.h"
#include "ft/string/strlen.h"
#include "ft/string/str_substring.h"
#include <stdlib.h>

t_str	str_str_substringing(t_const_str str, t_usize start, t_usize len)
{
	t_usize	len_str;
	t_usize	len_str_substring;
	t_str	out;

	if (str == NULL)
		return (NULL);
	len_str = str_len(str);
	if (start >= len_str)
		return (mem_alloc(1));
	len_str_substring = len_str - start + 1;
	if (len_str_substring > len)
		len_str_substring = len + 1;
	out = mem_alloc(sizeof(char) *  len_str_substring );
	if (out == NULL)
		return (NULL);
	str_l_copy(out, &str[start], len_str_substring );
	return (out);
}

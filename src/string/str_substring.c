/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_substring.c                                    :+:      :+:    :+:   */
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
#include "ft/string/substr.h"
#include <stdlib.h>

t_str	str_substring(t_const_str str, t_usize start, t_usize len)
{
	t_usize	len_str;
	t_usize	len_substr;
	t_str	out;

	if (str == NULL)
		return (NULL);
	len_str = str_len(str);
	if (start >= len_str)
		return (mem_alloc(1));
	len_substr = len_str - start + 1;
	if (len_substr > len)
		len_substr = len + 1;
	out = mem_alloc(sizeof(char) *  len_substr );
	if (out == NULL)
		return (NULL);
	str_l_copy(out, &str[start], len_substr );
	return (out);
}

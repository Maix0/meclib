/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_alloc_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:57:28 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 15:03:20 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ll/lstnew.h"
#include <stdlib.h>

t_list	*list_alloc_node(void *content)
{
	t_list	*out;

	out = mem_alloc(sizeof(t_list) * 1);
	if (out == NULL)
		return (NULL);
	out->content = content;
	out->next = NULL;
	return (out);
}

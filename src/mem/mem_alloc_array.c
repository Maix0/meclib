/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:53:21 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 15:00:31 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem/bzero.h"
#include "ft/mem/calloc.h"
#include <stdlib.h>

void	*mem_alloc_array(t_usize item_count, t_usize item_size)
{
	t_usize	multiplied;
	void	*outptr;

	multiplied = item_count * item_size;
	if (multiplied == 0 || multiplied / item_count != item_size)
		return (NULL);
	return mem_alloc(multiplied);
}

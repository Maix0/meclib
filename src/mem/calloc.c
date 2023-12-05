/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:53:21 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/10 15:06:10 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/bzero.h"
#include "me/mem/calloc.h"
#include <stdlib.h>

void	*me_calloc(t_usize item_count, t_usize item_size)
{
	t_usize	multiplied;
	void	*outptr;

	multiplied = item_count * item_size;
	if (multiplied == 0)
		return (malloc(0));
	if (multiplied / item_count != item_size)
	{
		return (NULL);
	}
	outptr = malloc(multiplied);
	if (outptr == NULL)
		return (NULL);
	me_bzero(outptr, multiplied);
	return (outptr);
}

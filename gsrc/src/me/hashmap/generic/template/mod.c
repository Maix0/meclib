/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:58:20 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/06 16:17:42 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hashmap/generic/template.h"
#include "me/mem/calloc.h"
#include "me/mem/malloc.h"
#include "me/mem/memcpy.h"
#include "me/types.h"
#include <stdlib.h>

t_hashmap	*new_hashmap(t_hash_fn hfunc, t_eq_fn cfunc, t_drop_fn drop)
{
	return (new_hashmap_c(hfunc, cfunc, drop, DEFAULT_BUCKETS));
}

t_hashmap	*new_hashmap_c(t_hash_fn hfunc, t_eq_fn cfunc, t_drop_fn drop,
		size_t buckets)
{
	t_hashmap	*hmap;

	hmap = malloc(sizeof(*hmap));
	if (hmap == NULL)
		return (NULL);
	hmap->buckets = me_calloc(buckets, sizeof(t_pair));
	hmap->num_buckets = buckets;
	hmap->hfunc = hfunc;
	hmap->cfunc = cfunc;
	hmap->drop = drop;
	if (hmap->buckets == NULL)
		return (free(hmap), NULL);
	return (hmap);
}

void	free_hashmap(t_hashmap *hmap)
{
	t_usize	index;

	index = 0;
	while (index < hmap->num_buckets)
	{
		if (hmap->buckets[index])
			hmap->drop(hmap->buckets[index]->kv);
	}
	free(hmap->buckets);
	free(hmap);
}

#undef __KEYTYPE__
#undef __VALTYPE__

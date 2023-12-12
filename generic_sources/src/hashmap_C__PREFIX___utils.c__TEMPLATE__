/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_C__PREFIX___utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:58:20 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/11 15:35:37 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hashmap/hashmap_C__PREFIX__.h"
#include "me/mem/mem_alloc.h"
#include "me/hash/sip.h"
#include "me/mem/mem_alloc_array.h"
#include "me/mem/mem_copy.h"
#include "me/types.h"
#include <stdlib.h>

C__VALTYPE__ *get_hashmap_C__PREFIX__(t_hashmap_C__PREFIX__ *hmap,
									  C__KEYTYPE__			*key)
{
	size_t				 hashed_key;
	t_entry_C__PREFIX__ *entry;

	hmap->hfunc(&hmap->hasher, key);
	hashed_key = hasher_finish(hmap->hasher);
	hmap->hasher = hasher_sip13_new();
	entry = hmap->buckets[hashed_key % hmap->num_buckets];
	while (entry != NULL)
	{
		if (!hmap->cfunc(&entry->kv.key, key))
			return (&entry->kv.val);
		entry = entry->next;
	}
	return (NULL);
}

void remove_hashmap_C__PREFIX__(t_hashmap_C__PREFIX__ *hmap, C__KEYTYPE__ *key)
{
	size_t				 hashed_key;
	t_entry_C__PREFIX__ *prev;
	t_entry_C__PREFIX__ *entry;

	hmap->hfunc(&hmap->hasher, key);
	hashed_key = hasher_finish(hmap->hasher);
	hmap->hasher = hasher_sip13_new();
	prev = NULL;
	entry = hashmap_get_entry__C__PREFIX__(hmap, hashed_key, key, &prev);
	if (entry == NULL)
		return;
	if (prev == NULL)
	{
		hmap->buckets[hashed_key % hmap->num_buckets] = entry->next;
	}
	else
	{
		prev->next = entry->next;
	}
	hmap->drop(entry->kv);
	free(entry);
	hmap->buckets[hashed_key % hmap->num_buckets] = NULL;
}

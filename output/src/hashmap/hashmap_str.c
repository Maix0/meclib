/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:58:20 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/08 16:49:38 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hashmap/hashmap_str.h"
#include "me/mem/mem_alloc_array.h"
#include "me/mem/malloc.h"
#include "me/mem/mem_copy.h"
#include "me/types.h"
#include <stdlib.h>

t_hashmap_str *new_hashmap_str(t_hash_str_fn hfunc,
											   t_eq_str_fn	 cfunc,
											   t_drop_str_fn drop)
{
	return (new_hashmap_with_buckets_str(hfunc, cfunc, drop,
												  DEFAULT_BUCKETS));
}

t_hashmap_str *new_hashmap_with_buckets_str(
	t_hash_str_fn hfunc, t_eq_str_fn cfunc,
	t_drop_str_fn drop, size_t buckets)
{
	t_hashmap_str *hmap;

	hmap = malloc(sizeof(*hmap));
	if (hmap == NULL)
		return (NULL);
	hmap->buckets = me_mem_alloc_array(buckets, sizeof(t_entry_str *));
	hmap->num_buckets = buckets;
	hmap->hfunc = hfunc;
	hmap->cfunc = cfunc;
	hmap->drop = drop;
	if (hmap->buckets == NULL)
		return ((void)free(hmap), NULL);
	return (hmap);
}

void drop_hashmap_str(t_hashmap_str *hmap)
{
	t_usize index;

	index = 0;
	while (index < hmap->num_buckets)
	{
		if (hmap->buckets[index])
		{
			hmap->drop(hmap->buckets[index]->kv);
			free(hmap->buckets[index]);
		}
		index++;
	}
	free(hmap->buckets);
	free(hmap);
}

void insert_hashmap_str(t_hashmap_str *hmap, t_str key,
								t_str value)
{
	size_t				 hashed_key = hmap->hfunc(&key);
	t_entry_str *prev = NULL;
	t_entry_str *entry = hmap->buckets[hashed_key % hmap->num_buckets];

	while (entry != NULL)
	{
		if (!hmap->cfunc(&entry->kv.key, &key))
		{
			prev = entry;
			break;
		}
		entry = entry->next;
	}

	if (entry == NULL)
	{
		entry = malloc(sizeof(t_entry_str));
		entry->hash_id = hashed_key;
		entry->kv = (t_kv_str){.key = key, .val = value};
		entry->next = NULL;

		if (prev == NULL)
		{
			hmap->buckets[hashed_key % hmap->num_buckets] = entry;
		}
		else
		{
			prev->next = entry;
		}
	}
	else
	{
		entry->kv.val = value;
	}
}

t_str *get_hashmap_str(t_hashmap_str *hmap,
									  t_str			*key)
{
	size_t				 hashed_key = hmap->hfunc(key);
	t_entry_str *entry = hmap->buckets[hashed_key % hmap->num_buckets];

	while (entry != NULL)
	{
		if (!hmap->cfunc(&entry->kv.key, key))
			return &entry->kv.val;
		entry = entry->next;
	}

	return NULL;
}

void remove_hashmap_str(t_hashmap_str *hmap, t_str *key)
{
	size_t				 hashed_key = hmap->hfunc(key);
	t_entry_str *prev = NULL;
	t_entry_str *entry = hmap->buckets[hashed_key % hmap->num_buckets];

	while (entry != NULL)
	{
		if (!hmap->cfunc(&entry->kv.key, key))
		{
			prev = entry;
			break;
		}
		entry = entry->next;
	}

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

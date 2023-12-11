/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_str.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:00:22 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/11 15:24:44 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_STR_H
# define HASHMAP_STR_H

# define DEFAULT_BUCKETS 750

# include "me/hash/hasher.h"
# include "me/types.h"
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_kv_str
{
	t_str				key;
	t_str				val;
}						t_kv_str;

typedef void			(*t_hash_str_fn)(t_hasher *hasher, t_str *key);
typedef void			(*t_drop_str_fn)(t_kv_str val);
typedef bool			(*t_eq_str_fn)(t_str *lhs, t_str *rhs);

typedef struct s_entry_str
{
	size_t				hash_id;
	t_kv_str			kv;
	struct s_entry_str	*next;
}						t_entry_str;

typedef struct s_hashmap_str
{
	t_entry_str			**buckets;
	size_t				num_buckets;
	t_hasher			hasher;
	t_hash_str_fn		hfunc;
	t_eq_str_fn			cfunc;
	t_drop_str_fn		drop;
}						t_hashmap_str;

t_hashmap_str			*new_hashmap_str(t_hash_str_fn hash, t_eq_str_fn cmp,
							t_drop_str_fn drop);
t_hashmap_str			*new_hashmap_with_buckets_str(t_hash_str_fn hash,
							t_eq_str_fn cmp, t_drop_str_fn drop, size_t cap);

void					drop_hashmap_str(t_hashmap_str *hmap);

void					insert_hashmap_str(t_hashmap_str *hmap, t_str key,
							t_str value);

t_str					*get_hashmap_str(t_hashmap_str *hmap, t_str *key);
void					remove_hashmap_str(t_hashmap_str *hmap, t_str *key);

t_entry_str				*hashmap_get_entry__str(t_hashmap_str *hmap,
							size_t hash, t_str *key, t_entry_str **prev);

#endif

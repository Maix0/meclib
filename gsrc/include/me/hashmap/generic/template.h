/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:00:22 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/06 16:10:33 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
# define TEMPLATE_H

# define DEFAULT_BUCKETS 7500

# include "me/mem/malloc.h"
# include "me/types.h"
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define __KEYTYPE__ char *
# define __VALTYPE__ int

typedef struct s_kv
{
	__KEYTYPE__		key;
	__VALTYPE__		val;
}					t_kv;

typedef size_t		(*t_hash_fn)(__KEYTYPE__ *key);
typedef size_t		(*t_drop_fn)(t_kv val);
typedef bool		(*t_eq_fn)(__KEYTYPE__ *lhs, __KEYTYPE__ *rhs);

typedef struct s_pair
{
	size_t			hash_id;
	t_kv			kv;
	struct s_pair	*next;
}					t_pair;

typedef struct s_hashmap
{
	t_pair			**buckets;
	size_t			num_buckets;
	t_hash_fn		hfunc;
	t_eq_fn			cfunc;
	t_drop_fn		drop;
}					t_hashmap;

t_hashmap			*new_hashmap(t_hash_fn hash, t_eq_fn cmp, t_drop_fn drop);
t_hashmap			*new_hashmap_c(t_hash_fn hash, t_eq_fn cmp, t_drop_fn drop,
						size_t cap);

void				free_hashmap(t_hashmap *hmap);

void				insert_hashmap(t_hashmap *hmap, __KEYTYPE__ key,
						__VALTYPE__ value);

__VALTYPE__			*get_hashmap(t_hashmap *hmap, __KEYTYPE__ *key);
void				remove_hashmap(t_hashmap *hmap, __KEYTYPE__ *key);

#endif

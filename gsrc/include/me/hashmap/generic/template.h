/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:00:22 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/06 16:26:36 by maiboyer         ###   ########.fr       */
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

# define C_KEYTYPE__ char *
# define C_VALTYPE__ int

typedef struct s_kv
{
	C_KEYTYPE__		key;
	C_VALTYPE__		val;
}					t_kv;

typedef size_t		(*t_hash_fn)(C_KEYTYPE__ *key);
typedef size_t		(*t_drop_fn)(t_kv val);
typedef bool		(*t_eq_fn)(C_KEYTYPE__ *lhs, C_KEYTYPE__ *rhs);

typedef struct s_entry
{
	size_t			hash_id;
	t_kv			kv;
	struct s_entry	*next;
}					t_entry;

typedef struct s_hashmap
{
	t_entry			**buckets;
	size_t			num_buckets;
	t_hash_fn		hfunc;
	t_eq_fn			cfunc;
	t_drop_fn		drop;
}					t_hashmap;

t_hashmap			*new_hashmap(t_hash_fn hash, t_eq_fn cmp, t_drop_fn drop);
t_hashmap			*new_hashmap_c(t_hash_fn hash, t_eq_fn cmp, t_drop_fn drop,
						size_t cap);

void				drop_hashmap(t_hashmap hmap);

void				insert_hashmap(t_hashmap *hmap, C_KEYTYPE__ key,
						C_VALTYPE__ value);

C_VALTYPE__			*get_hashmap(t_hashmap *hmap, C_KEYTYPE__ *key);
void				remove_hashmap(t_hashmap *hmap, C_KEYTYPE__ *key);

#endif

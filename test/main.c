/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:24:07 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/08 17:01:12 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hashmap/hashmap_str.h"
#include "me/vec/vec_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t me_hash_str(t_str *key)
{
	t_str  k = *key;
	size_t out = 0;
	while (*k)
	{
		out += (size_t)*k;
		k++;
	}
	return out;
}

static bool me_cmp_str(t_str *lhs, t_str *rhs)
{
	return strcmp((t_const_str)lhs, (t_const_str)rhs) == 0;
}

static void me_free_kv_str(t_kv_str kv)
{
	free(kv.key);
	free(kv.val);
}

int main()
{
	t_str key;

	t_hashmap_str *hmap =
		new_hashmap_str(&me_hash_str, &me_cmp_str, &me_free_kv_str);

	insert_hashmap_str(hmap, str_clone("BANANE"), str_clone("STUFF"));
	insert_hashmap_str(hmap, str_clone("POMME"), str_clone("OI"));
	insert_hashmap_str(hmap, str_clone("YESS"), str_clone("YAS"));
	key = "BANANE";
	printf("hmap[%s] = %s\n", key, *get_hashmap_str(hmap, &key));
	key = "POMME";
	printf("hmap[%s] = %s\n", key, *get_hashmap_str(hmap, &key));
	key = "YESS";
	printf("hmap[%s] = %s\n", key, *get_hashmap_str(hmap, &key));

	t_vec_str vector = me_vec_str_new(1);
	me_vec_str_push(&vector, "BANANE");
	me_vec_str_push(&vector, "POMME");
	me_vec_str_push(&vector, "POIRE");

	t_str val;
	while (!me_vec_str_pop(&vector, &val))
	{
		printf("%s\n", val);
	}
	me_vec_str_free(vector, NULL);


	drop_hashmap_str(hmap);
}

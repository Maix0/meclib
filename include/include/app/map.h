/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:57:14 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/31 17:55:26 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "me/vec2/vec2.h"
# include "me/hashmap/hashmap_tile.h"
# include "me/types.h"
# include "me/vec/vec_tile.h"

typedef struct s_map
{
	t_vec_tile		map;
	t_usize			width;
	t_usize			height;
	t_vi2d			start;
	t_isize			total_coin;

}					t_map;

t_map				parse_from_path(t_str path);
bool				get_tile(t_map *map, t_vi2d vi2d, t_tile *out);
void				set_tile(t_map *map, t_vi2d vi2d, t_tile t);
t_error				check_if_map_valid(t_map *map, t_str *reason);

static inline void	map_free(t_map map)
{
	vec_tile_free(map.map);
}

#endif

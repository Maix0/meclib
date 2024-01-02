/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:02:30 by maiboyer          #+#    #+#             */
/*   Updated: 2024/01/02 12:13:32 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "app/map.h"
# include "me/hashmap/hashmap_tile.h"
# include "me/types.h"
# include "me/vec2/vec2.h"

typedef struct s_data
{
	t_vi2d			player;
	t_hashmap_tile	*tiles;
	t_map			map;
	t_i32			coin;
	t_i32			total_moves;
	t_tile			player_tile;
}					t_data;

#endif /* MAIN_H */

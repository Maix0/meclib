/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:00:21 by maiboyer          #+#    #+#             */
/*   Updated: 2024/01/02 12:22:15 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

# include "me/types.h"

# define BIT1 0b0000000001
# define BIT2 0b0000000010
# define BIT3 0b0000000100
# define BIT4 0b0000001000
# define BIT5 0b0000010000
# define BIT6 0b0000100000
# define BIT7 0b0001000000
# define BIT8 0b0010000000
# define BIT9 0b0100000000
# define BITA 0b1000000000
# define BIT_CAN_GO 0b10000000000

typedef enum e_tile
{
	TILE_ISWALL = BIT5 | BIT6,
	TILE_INNER_TL_TR_BL_BR = BIT5 | (BIT4 | BIT3 | BIT2 | BIT1),
	TILE_INNER_TL_TR_BL___ = BIT5 | (BIT4 | BIT3 | BIT2),
	TILE_INNER_TL_TR____BR = BIT5 | (BIT4 | BIT3 | BIT1),
	TILE_INNER_TL_TR______ = BIT5 | (BIT4 | BIT3),
	TILE_INNER_TL____BL_BR = BIT5 | (BIT4 | BIT2 | BIT1),
	TILE_INNER_TL____BL___ = BIT5 | (BIT4 | BIT2),
	TILE_INNER_TL_______BR = BIT5 | (BIT4 | BIT1),
	TILE_INNER_TL_________ = BIT5 | (BIT4),
	TILE_INNER____TR_BL_BR = BIT5 | (BIT3 | BIT2 | BIT1),
	TILE_INNER____TR_BL___ = BIT5 | (BIT3 | BIT2),
	TILE_INNER____TR____BR = BIT5 | (BIT3 | BIT1),
	TILE_INNER____TR______ = BIT5 | (BIT3),
	TILE_INNER_______BL_BR = BIT5 | (BIT2 | BIT1),
	TILE_INNER_______BL___ = BIT5 | (BIT2),
	TILE_INNER__________BR = BIT5 | (BIT1),
	TILE_WALLS_UP_DW_LF_RG = BIT6 | (BIT4 | BIT3 | BIT2 | BIT1),
	TILE_WALLS_UP_DW_LF___ = BIT6 | (BIT4 | BIT3 | BIT2),
	TILE_WALLS_UP_DW____RG = BIT6 | (BIT4 | BIT3 | BIT1),
	TILE_WALLS_UP_DW______ = BIT6 | (BIT4 | BIT3),
	TILE_WALLS_UP____LF_RG = BIT6 | (BIT4 | BIT2 | BIT1),
	TILE_WALLS_UP____LF___ = BIT6 | (BIT4 | BIT2),
	TILE_WALLS_UP_______RG = BIT6 | (BIT4 | BIT1),
	TILE_WALLS_UP_________ = BIT6 | (BIT4),
	TILE_WALLS____DW_LF_RG = BIT6 | (BIT3 | BIT2 | BIT1),
	TILE_WALLS____DW_LF___ = BIT6 | (BIT3 | BIT2),
	TILE_WALLS____DW____RG = BIT6 | (BIT3 | BIT1),
	TILE_WALLS____DW______ = BIT6 | (BIT3),
	TILE_WALLS_______LF_RG = BIT6 | (BIT2 | BIT1),
	TILE_WALLS_______LF___ = BIT6 | (BIT2),
	TILE_WALLS__________RG = BIT6 | (BIT1),
	TILE_WALLS____________ = BIT6,
	TILE_EXIT = BIT7,
	TILE_COIN = BIT8,
	TILE_START = BIT9,
	TILE_FLOOR = BITA,
	TILE_PLAYER_U = BITA << 2 | BIT1,
	TILE_PLAYER_D = BITA << 2 | BIT2,
	TILE_PLAYER_L = BITA << 2 | BIT3,
	TILE_PLAYER_R = BITA << 2 | BIT4,
}							t_tile;

typedef struct s_tile_paths
{
	t_const_str				inner_prefix;
	t_const_str				inner_vals[4];
	t_const_str				walls_prefix;
	t_const_str				walls_vals[4];
	t_const_str				floor;
	t_const_str				start;
	t_const_str				exit;
	t_const_str				coin;
	t_const_str				player;
	t_const_str				player_vals[4];

}							t_tiles_paths;

static inline t_tiles_paths	get_tile_paths(void)
{
	return ((t_tiles_paths){
		.inner_prefix = "./textures/inner/",
		.inner_vals = {"tl", "tr", "bl", "br"},
		.walls_prefix = "./textures/walls/",
		.walls_vals = {"up", "dw", "lf", "rg"},
		.floor = "./textures/floor",
		.start = "./textures/start",
		.exit = "./textures/exit",
		.coin = "./textures/coin",
		.player = "./textures/player",
		.player_vals = {"u", "d", "l", "r"},
	});
}

#endif

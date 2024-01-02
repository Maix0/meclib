/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:31:57 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/31 17:57:15 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H

# include "app/map.h"
# include "app/tile.h"
# include "me/types.h"

typedef struct s_map_check
{
	t_map	*map;
	bool	error;
	t_str	*reason;
	t_usize	start;
	t_usize	exit;
}			t_map_check;

#endif /* MAP_CHECK_H */

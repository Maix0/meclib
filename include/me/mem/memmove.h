/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:27:20 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/08 01:25:24 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMMOVE_H
# define MEMMOVE_H

# include "me/types.h"

void	*me_mem_move(void *destination, const void *source, t_usize count);

#endif

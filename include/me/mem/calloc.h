/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc_array.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:21 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:48 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLOC_H
# define CALLOC_H
# include "me/types.h"

void	*me_mem_alloc_array(t_usize item_count, t_usize item_size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_find_bytes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:16:02 by maiboyer          #+#    #+#             */
/*   Updated: 2024/01/05 17:56:39 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_FIND_H
#define MEM_FIND_H

#include "me/types.h"

void *mem_find_bytes(void *buf, t_u8 *find, t_usize find_count, t_usize count);

#endif

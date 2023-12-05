/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:27:20 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/10 14:33:21 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMCPY_H
# define MEMCPY_H

# include "me/types.h"

void	*me_memcpy(void *destination, const void *source, t_usize count);

#endif

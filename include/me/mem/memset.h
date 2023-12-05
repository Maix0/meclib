/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:27:20 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/06 11:37:29 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMSET_H
# define MEMSET_H

# include "me/types.h"

void	*me_memset(void *buf, t_i32 fill_by, t_usize count);

#endif

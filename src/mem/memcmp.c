/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:16:02 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/08 16:25:53 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/memcmp.h"

t_i32 me_memcmp(const void *lhs, const void *rhs, t_usize count)
{
	t_usize		i;
	const t_u8 *lhs_;
	const t_u8 *rhs_;

	i = 0;
	lhs_ = (const t_u8 *)lhs;
	rhs_ = (const t_u8 *)rhs;
	while (i < count)
	{
		if (lhs_[i] - rhs_[i])
			return ((t_i32)(lhs_[i] - rhs_[i]));
		i++;
	}
	return (0);
}

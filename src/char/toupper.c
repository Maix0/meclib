/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:47:50 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/04 16:51:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char/islower.h"
#include "ft/char/toupper.h"

t_i32	me_toupper(t_i32 chr)
{
	if (me_islower(chr))
		return (chr - ('a' - 'A'));
	else
		return (chr);
}

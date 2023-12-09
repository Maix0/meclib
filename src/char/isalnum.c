/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:19:40 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/09 19:38:51 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char/isalnum.h"
#include "ft/char/isalpha.h"
#include "ft/char/isdigit.h"

t_i32	me_isalnum(t_i32 chr)
{
	return (me_isalpha(chr) || me_isdigit(chr));
}

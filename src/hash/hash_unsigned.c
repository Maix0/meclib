/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:25:23 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/11 17:25:39 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hash/hasher.h"
#include "me/types.h"

void	hasher_write_bytes(t_hasher *hasher, t_u8 *bytes, t_usize count)
{
	hasher->hash_bytes(hasher->hasher, bytes, count);
}

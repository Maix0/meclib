/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:49 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:48 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/malloc.h"

void *me_malloc(t_usize size) {
  void *out;
  size_t i;

  out = malloc(size);
  while (out && i < size)
    ((t_u8 *)out)[i++] = 0;
  return out;
}

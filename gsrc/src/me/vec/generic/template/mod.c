/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:46:28 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/05 19:38:31 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/calloc.h"
#include "me/mem/memcpy.h"
#include "me/types.h"
#include "me/vec/generic/g_vec___TYPENAME__.h"
#include <stdlib.h>

t_vec___TYPENAME__ me_vec___TYPENAME___new(t_usize capacity) {
  t_vec___TYPENAME__ out;

  out = (t_vec___TYPENAME__){0};
  out.buffer = me_calloc(capacity, sizeof(__TYPENAME__));
  if (out.buffer)
    out.capacity = capacity;
  return (out);
}

/// Return true in case of an error
bool me_vec___TYPENAME___push(t_vec___TYPENAME__ *vec, __TYPENAME__ element) {
  __TYPENAME__ *temp_buffer;
  size_t new_capacity;

  if (vec == NULL)
    return (true);
  if (vec->len + 1 > vec->capacity) {
    new_capacity = (vec->capacity * 3) / 2 + 1;
    while (vec->len + 1 > new_capacity)
      new_capacity = (new_capacity * 3) / 2 + 1;
    temp_buffer = me_calloc(new_capacity, sizeof(__TYPENAME__));
    if (temp_buffer == NULL)
      return (true);
    temp_buffer[0] = 0;
    me_memcpy(temp_buffer, vec->buffer, vec->len * sizeof(__TYPENAME__));
    free(vec->buffer);
    vec->buffer = temp_buffer;
    vec->capacity = new_capacity;
  }
  vec->buffer[vec->len] = element;
  vec->len += 1;
  return (false);
}

/// Return true if the vector is empty
bool me_vec___TYPENAME___pop(t_vec___TYPENAME__ *vec, __TYPENAME__ *value) {
  if (vec->len == 0 || value == NULL)
    return (vec->len == 0 || value != NULL);
  vec->len--;
  *value = vec->buffer[vec->len];
  return false;
}
void me_vec___TYPENAME___free(t_vec___TYPENAME__ vec,
                              void (*free_elem)(__TYPENAME__)) {

  if (free_elem) {
    while (vec.len) {
      free_elem(vec.buffer[vec.len - 1]);
      vec.len--;
    }
  }
  free(vec.buffer);
}

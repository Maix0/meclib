/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:46:53 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/05 19:38:44 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
#define TEMPLATE_H

__TYPEHEADER__
#include "me/types.h"

typedef struct {
  t_usize len;
  t_usize capacity;
  __TYPENAME__ *buffer;
} t_vec___TYPENAME__;

t_vec___TYPENAME__ me_vec___TYPENAME___new(t_usize capacity);
bool me_vec___TYPENAME___push(t_vec___TYPENAME__ *vec, __TYPENAME__ element);
bool me_vec___TYPENAME___pop(t_vec___TYPENAME__ *vec, __TYPENAME__ *value);
void me_vec___TYPENAME___free(t_vec___TYPENAME__ vec,
                              void (*free_elem)(__TYPENAME__));

#endif

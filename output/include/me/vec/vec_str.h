/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_str.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:46:53 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/07 19:17:40 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_STR_H
#define VEC_STR_H

#ifdef GENERIC_WRITING
#define char * char
#define #include "me/types/t_str.h"
#endif

#include "me/types/t_str.h"
#include "me/types.h"

typedef struct {
  t_usize len;
  t_usize capacity;
  char * *buffer;
} t_vec_str;

t_vec_str me_vec_str_new(t_usize capacity);
bool me_vec_str_push(t_vec_str *vec, char * element);
bool me_vec_str_pop(t_vec_str *vec, char * *value);
void me_vec_str_free(t_vec_str vec,
                             void (*free_elem)(char *));

#endif

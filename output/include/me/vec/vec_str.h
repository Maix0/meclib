/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_str.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:46:53 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 17:53:00 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_STR_H
# define VEC_STR_H


# include "me/types.h"

typedef struct s_vec_str
{
	t_usize			len;
	t_usize			capacity;
	t_str	*buffer;
}					t_vec_str;

t_vec_str	me_vec_str_new(t_usize capacity);
bool				me_vec_str_push(t_vec_str *vec,
						t_str element);
bool				me_vec_str_pop(t_vec_str *vec,
						t_str *value);
void				me_vec_str_free(t_vec_str vec,
						void (*free_elem)(t_str));

#endif

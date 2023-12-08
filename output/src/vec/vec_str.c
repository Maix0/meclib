/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:46:28 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/08 16:58:00 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/vec/vec_str.h"
#include "me/mem/calloc.h"
#include "me/mem/memcpy.h"
#include "me/types.h"
#include <stdlib.h>

#ifdef GENERIC_WRITING
# define char * char
#endif

t_vec_str me_vec_str_new(t_usize capacity)
{
	t_vec_str out;

	out = (t_vec_str){0};
	out.buffer = me_calloc(capacity, sizeof(char *));
	if (out.buffer)
		out.capacity = capacity;
	return (out);
}

/// Return true in case of an error
bool me_vec_str_push(t_vec_str *vec, char * element)
{
	char * *temp_buffer;
	size_t		   new_capacity;

	if (vec == NULL)
		return (true);
	if (vec->len + 1 > vec->capacity)
	{
		new_capacity = (vec->capacity * 3) / 2 + 1;
		while (vec->len + 1 > new_capacity)
			new_capacity = (new_capacity * 3) / 2 + 1;
		temp_buffer = me_calloc(new_capacity, sizeof(char *));
		if (temp_buffer == NULL)
			return (true);
		temp_buffer[0] = 0;
		me_memcpy(temp_buffer, vec->buffer, vec->len * sizeof(char *));
		free(vec->buffer);
		vec->buffer = temp_buffer;
		vec->capacity = new_capacity;
	}
	vec->buffer[vec->len] = element;
	vec->len += 1;
	return (false);
}

/// Return true if the vector is empty
bool me_vec_str_pop(t_vec_str *vec, char * *value)
{
	if (vec->len == 0 || value == NULL)
		return (vec->len == 0 || value != NULL);
	vec->len--;
	*value = vec->buffer[vec->len];
	return false;
}
void me_vec_str_free(t_vec_str vec,
							 void (*free_elem)(char *))
{

	if (free_elem)
	{
		while (vec.len)
		{
			free_elem(vec.buffer[vec.len - 1]);
			vec.len--;
		}
	}
	free(vec.buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:46:28 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/09 17:54:11 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/mem/mem_alloc_array.h"
#include "me/mem/mem_copy.h"
#include "me/types.h"
#include "me/vec/vec_str.h"
#include <stdlib.h>

t_vec_str	vec_str_new(t_usize capacity)
{
	t_vec_str	out;

	out = (t_vec_str){0};
	out.buffer = mem_alloc_array(capacity, sizeof(t_str));
	if (out.buffer)
		out.capacity = capacity;
	return (out);
}

/// Return true in case of an error
bool	vec_str_push(t_vec_str *vec, t_str element)
{
	t_str	*temp_buffer;
	size_t	new_capacity;

	if (vec == NULL)
		return (true);
	if (vec->len + 1 > vec->capacity)
	{
		new_capacity = (vec->capacity * 3) / 2 + 1;
		while (vec->len + 1 > new_capacity)
			new_capacity = (new_capacity * 3) / 2 + 1;
		temp_buffer = mem_alloc_array(new_capacity, sizeof(t_str));
		if (temp_buffer == NULL)
			return (true);
		temp_buffer[0] = 0;
		mem_copy(temp_buffer, vec->buffer, vec->len * sizeof(t_str));
		free(vec->buffer);
		vec->buffer = temp_buffer;
		vec->capacity = new_capacity;
	}
	vec->buffer[vec->len] = element;
	vec->len += 1;
	return (false);
}

/// Return true if the vector is empty
bool	vec_str_pop(t_vec_str *vec, t_str *value)
{
	if (vec->len == 0 || value == NULL)
		return (vec->len == 0 || value != NULL);
	vec->len--;
	*value = vec->buffer[vec->len];
	return (false);
}

void	vec_str_free(t_vec_str vec, void (*free_elem)(t_str))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:24:07 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/05 19:32:22 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/vec/generic/g_vec_char.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  t_vec_char vec = me_vec_char_new(1);
  me_vec_char_push(&vec, 'h');
  me_vec_char_push(&vec, 'e');
  me_vec_char_push(&vec, 'l');
  me_vec_char_push(&vec, 'l');
  me_vec_char_push(&vec, 'o');
  me_vec_char_push(&vec, ' ');
  me_vec_char_push(&vec, 'w');
  me_vec_char_push(&vec, 'o');
  me_vec_char_push(&vec, 'r');
  me_vec_char_push(&vec, 'l');
  me_vec_char_push(&vec, 'd');
  me_vec_char_push(&vec, '!');
  me_vec_char_push(&vec, '\0');

  printf("%s\n", vec.buffer);
  me_vec_char_free(vec, NULL);
}

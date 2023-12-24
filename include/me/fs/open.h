/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:29:38 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/24 18:57:57 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_H
# define OPEN_H

# include "me/types.h"

bool	me_open(t_const_str path, bool read, bool write, t_file *file_out);

#endif

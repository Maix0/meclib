/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sip_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maix <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:34:10 by maix              #+#    #+#             */
/*   Updated: 2023/12/10 20:19:11 by maix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIP_UTILS_H
#define SIP_UTILS_H
#include "me/hash/sip.h"
#include "me/types.h"

void		compress(t_sip_state *state);
t_sip_state create_state_with_key(t_u64 k0, t_u64 k1);

#endif

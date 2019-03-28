/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:34:50 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 20:01:15 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t	reverse_bits(uint32_t value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |\
	(value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

uint64_t	reverse_bits64(uint64_t value)
{
	value = (value & 0x00000000FFFFFFFF) << 32
		| (value & 0xFFFFFFFF00000000) >> 32;
	value = (value & 0x0000FFFF0000FFFF) << 16
		| (value & 0xFFFF0000FFFF0000) >> 16;
	value = (value & 0x00FF00FF00FF00FF) << 8
		| (value & 0xFF00FF00FF00FF00) >> 8;
	return (value);
}

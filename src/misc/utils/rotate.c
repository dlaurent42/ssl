/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:10:57 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 19:55:24 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t	rotate_left(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

uint32_t	rotate_right(uint32_t x, uint32_t c)
{
	return ((x >> c) | (x << (32 - c)));
}

uint64_t	rotate_left64(uint64_t x, uint64_t c)
{
	return ((x << c) | (x >> (64 - c)));
}

uint64_t	rotate_right64(uint64_t x, uint64_t c)
{
	return ((x >> c) | (x << (64 - c)));
}

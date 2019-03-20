/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:10:57 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/20 15:11:13 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

unsigned int	left_rotate(const unsigned int value, int shift)
{
	if ((shift &= sizeof(value) * 8 - 1) == 0)
		return (value);
	return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}

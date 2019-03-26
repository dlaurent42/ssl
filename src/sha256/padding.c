/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:16:18 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/26 14:44:28 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t	*prepare_sha256_padded_message(
	char *message, unsigned long long len, unsigned long long offset)
{
	int			i;
	uint32_t	*new;

	i = 0;
	if (!(new = (uint32_t *)ft_memalloc(512)))
		return (NULL);
	new = ft_memcpy((void *)new, (void *)message, len);
	((char *)new)[len] = 0x80;
	while (i < ((int)offset * 16) - 1)
	{
		new[i] = ((new[i] >> 24) |
			((new[i] & 0xff0000) >> 8) |
			((new[i] & 0xff00) << 8) | (new[i] << 24));
		i++;
	}
	new[((offset * 512 - 64) / 32) + 1] = len * 8;
	return (new);
}

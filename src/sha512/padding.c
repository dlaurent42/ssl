/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:16:18 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 19:53:49 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char	*prepare_sha512_padded_message(char *msg, uint64_t len, uint64_t plen)
{
	char				*new;

	if (!(new = (char *)ft_memalloc((plen))))
		return (NULL);
	new = ft_memcpy((void *)new, (void *)msg, len);
	new[len] = (unsigned char)0b10000000;
	// new[plen - 16] = (8 * len >> 56) & 0xFF;
	// new[plen - 15] = (8 * len >> 48) & 0xFF;
	// new[plen - 14] = (8 * len >> 40) & 0xFF;
	// new[plen - 13] = (8 * len >> 32) & 0xFF;
	// new[plen - 12] = (8 * len >> 24) & 0xFF;
	// new[plen - 11] = (8 * len >> 16) & 0xFF;
	// new[plen - 10] = (8 * len >> 8) & 0xFF;
	// new[plen - 9] = (8 * len) & 0xFF;
	new[plen - 8] = (8 * len >> 56) & 0xFF;
	new[plen - 7] = (8 * len >> 48) & 0xFF;
	new[plen - 6] = (8 * len >> 40) & 0xFF;
	new[plen - 5] = (8 * len >> 32) & 0xFF;
	new[plen - 4] = (8 * len >> 24) & 0xFF;
	new[plen - 3] = (8 * len >> 16) & 0xFF;
	new[plen - 2] = (8 * len >> 8) & 0xFF;
	new[plen - 1] = (8 * len) & 0xFF;
	return (new);
}

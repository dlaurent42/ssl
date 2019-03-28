/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:16:18 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 17:54:31 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char	*prepare_sha224_padded_message(
	char *message, unsigned long long len, unsigned long long padded_len)
{
	char				*new;

	if (!(new = (char *)ft_memalloc((padded_len))))
		return (NULL);
	new = ft_memcpy((void *)new, (void *)message, len);
	new[len] = (unsigned char)0b10000000;
	new[padded_len - 8] = (8 * len >> 56) & 0xFF;
	new[padded_len - 7] = (8 * len >> 48) & 0xFF;
	new[padded_len - 6] = (8 * len >> 40) & 0xFF;
	new[padded_len - 5] = (8 * len >> 32) & 0xFF;
	new[padded_len - 4] = (8 * len >> 24) & 0xFF;
	new[padded_len - 3] = (8 * len >> 16) & 0xFF;
	new[padded_len - 2] = (8 * len >> 8) & 0xFF;
	new[padded_len - 1] = (8 * len) & 0xFF;
	return (new);
}

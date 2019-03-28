/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:16:12 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 17:28:54 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_sha256	*initialize_sha256_structure(char *input, size_t size)
{
	t_sha256	*sha256;

	if (!(sha256 = (t_sha256 *)ft_memalloc(sizeof(t_sha256))))
		return (NULL);
	sha256->status[0] = 0x6a09e667;
	sha256->status[1] = 0xbb67ae85;
	sha256->status[2] = 0x3c6ef372;
	sha256->status[3] = 0xa54ff53a;
	sha256->status[4] = 0x510e527f;
	sha256->status[5] = 0x9b05688c;
	sha256->status[6] = 0x1f83d9ab;
	sha256->status[7] = 0x5be0cd19;
	sha256->initial_length = size;
	if (sha256->initial_length % 64 == 56)
		sha256->padded_str_length = 72 + sha256->initial_length;
	else
		sha256->padded_str_length = (sha256->initial_length % 64 < 56)
			? 64 - sha256->initial_length % 64 + sha256->initial_length
			: 128 - sha256->initial_length % 64 + sha256->initial_length;
	sha256->padded_str = prepare_sha256_padded_message(
		input,
		sha256->initial_length,
		sha256->padded_str_length);
	return (sha256);
}

void		destroy_sha256_structure(t_sha256 *sha256)
{
	if (!sha256)
		return ;
	if (sha256->padded_str)
		free(sha256->padded_str);
	if (sha256->w)
		free(sha256->w);
	free(sha256);
}

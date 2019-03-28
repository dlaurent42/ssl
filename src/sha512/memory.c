/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:18:35 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 19:29:01 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_sha512	*initialize_sha512_structure(char *input, size_t size)
{
	t_sha512	*sha512;

	if (!(sha512 = (t_sha512 *)ft_memalloc(sizeof(t_sha512))))
		return (NULL);
	sha512->status[0] = 0x6a09e667f3bcc908;
	sha512->status[1] = 0xbb67ae8584caa73b;
	sha512->status[2] = 0x3c6ef372fe94f82b;
	sha512->status[3] = 0xa54ff53a5f1d36f1;
	sha512->status[4] = 0x510e527fade682d1;
	sha512->status[5] = 0x9b05688c2b3e6c1f;
	sha512->status[6] = 0x1f83d9abfb41bd6b;
	sha512->status[7] = 0x5be0cd19137e2179;
	sha512->initial_length = size;
	if (sha512->initial_length % 128 == 112)
		sha512->padded_str_length = 144 + sha512->initial_length;
	else
		sha512->padded_str_length = (sha512->initial_length % 128 < 112)
			? 128 - sha512->initial_length % 128 + sha512->initial_length
			: 256 - sha512->initial_length % 128 + sha512->initial_length;
	sha512->padded_str = prepare_sha512_padded_message(
		input,
		sha512->initial_length,
		sha512->padded_str_length);
	return (sha512);
}

void		destroy_sha512_structure(t_sha512 *sha512)
{
	if (!sha512)
		return ;
	if (sha512->padded_str)
		free(sha512->padded_str);
	if (sha512->w)
		free(sha512->w);
	free(sha512);
}

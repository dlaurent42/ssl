/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:16:12 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 17:56:04 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_sha224	*initialize_sha224_structure(char *input, size_t size)
{
	t_sha224	*sha224;

	if (!(sha224 = (t_sha224 *)ft_memalloc(sizeof(t_sha224))))
		return (NULL);
	sha224->status[0] = 0xc1059ed8;
	sha224->status[1] = 0x367cd507;
	sha224->status[2] = 0x3070dd17;
	sha224->status[3] = 0xf70e5939;
	sha224->status[4] = 0xffc00b31;
	sha224->status[5] = 0x68581511;
	sha224->status[6] = 0x64f98fa7;
	sha224->status[7] = 0xbefa4fa4;
	sha224->initial_length = size;
	if (sha224->initial_length % 64 == 56)
		sha224->padded_str_length = 72 + sha224->initial_length;
	else
		sha224->padded_str_length = (sha224->initial_length % 64 < 56)
			? 64 - sha224->initial_length % 64 + sha224->initial_length
			: 128 - sha224->initial_length % 64 + sha224->initial_length;
	sha224->padded_str = prepare_sha224_padded_message(
		input,
		sha224->initial_length,
		sha224->padded_str_length);
	return (sha224);
}

void		destroy_sha224_structure(t_sha224 *sha224)
{
	if (!sha224)
		return ;
	if (sha224->padded_str)
		free(sha224->padded_str);
	if (sha224->w)
		free(sha224->w);
	free(sha224);
}

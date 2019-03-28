/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:18:35 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 00:24:50 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_sha384	*initialize_sha384_structure(char *input, size_t size)
{
	t_sha384	*sha384;

	if (!(sha384 = (t_sha384 *)ft_memalloc(sizeof(t_sha384))))
		return (NULL);
	sha384->status[0] = 0xcbbb9d5dc1059ed8;
	sha384->status[1] = 0x629a292a367cd507;
	sha384->status[2] = 0x9159015a3070dd17;
	sha384->status[3] = 0x152fecd8f70e5939;
	sha384->status[4] = 0x67332667ffc00b31;
	sha384->status[5] = 0x8eb44a8768581511;
	sha384->status[6] = 0xdb0c2e0d64f98fa7;
	sha384->status[7] = 0x47b5481dbefa4fa4;
	sha384->initial_length = size;
	if (sha384->initial_length % 128 == 112)
		sha384->padded_str_length = 144 + sha384->initial_length;
	else
		sha384->padded_str_length = (sha384->initial_length % 128 < 112)
			? 128 - sha384->initial_length % 128 + sha384->initial_length
			: 256 - sha384->initial_length % 128 + sha384->initial_length;
	sha384->padded_str = prepare_sha384_padded_message(
		input,
		sha384->initial_length,
		sha384->padded_str_length);
	return (sha384);
}

void		destroy_sha384_structure(t_sha384 *sha384)
{
	if (!sha384)
		return ;
	if (sha384->padded_str)
		free(sha384->padded_str);
	if (sha384->w)
		free(sha384->w);
	free(sha384);
}

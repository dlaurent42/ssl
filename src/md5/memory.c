/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:12:21 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/22 16:31:50 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_md5		*initialize_md5_structure(char *input)
{
	t_md5	*md5;

	if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
		return (NULL);
	md5->h0 = 0x67452301;
	md5->h1 = 0xEFCDAB89;
	md5->h2 = 0x98BADCFE;
	md5->h3 = 0x10325476;
	md5->initial_length = strlenu(input);
	if (md5->initial_length % 64 == 56)
		md5->padded_str_length = 72 + md5->initial_length;
	else
		md5->padded_str_length = (md5->initial_length % 64 < 56)
			? 64 - md5->initial_length % 64 + md5->initial_length
			: 128 - md5->initial_length % 64 + md5->initial_length;
	md5->padded_str = prepare_padded_message(
		input,
		md5->initial_length,
		md5->padded_str_length);
	return (md5);
}

void		destroy_md5_structure(t_md5 *md5)
{
	if (!md5)
		return ;
	ft_strdel(&md5->padded_str);
	free(md5);
}

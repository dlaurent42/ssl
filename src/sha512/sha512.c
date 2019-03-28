/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:17:54 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 18:55:00 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*convert_output(t_sha512 *sha512)
{
	int		i;
	char	*output;

	i = 0;
	output = NULL;
	while (i < 8)
	{
		output = ft_strjoinf(output,
			prepend_zeros_to_hex(
				ulltoa_base("0123456789abcdef", sha512->status[i]), 16),
			3);
		i++;
	}
	return (output);
}

char		*convert_sha512(char *input, size_t size)
{
	char			*output;
	t_sha512		*sha512;

	if (!(sha512 = initialize_sha512_structure(input, size)))
		return (NULL);
	process_sha512(&sha512);
	output = convert_output(sha512);
	destroy_sha512_structure(sha512);
	return (output);
}

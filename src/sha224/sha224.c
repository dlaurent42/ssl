/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:32 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 17:56:18 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*convert_output(t_sha224 *sha224)
{
	int		i;
	char	*output;

	i = 0;
	output = NULL;
	while (i < 7)
	{
		output = ft_strjoinf(output,
			prepend_zeros_to_hex(
				ulltoa_base("0123456789abcdef", sha224->status[i])),
			3);
		i++;
	}
	return (output);
}

char		*convert_sha224(char *input, size_t size)
{
	char			*output;
	t_sha224		*sha224;

	if (!(sha224 = initialize_sha224_structure(input, size)))
		return (NULL);
	process_sha224(&sha224);
	output = convert_output(sha224);
	destroy_sha224_structure(sha224);
	return (output);
}

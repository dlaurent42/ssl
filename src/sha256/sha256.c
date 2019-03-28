/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:32 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 18:54:54 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*convert_output(t_sha256 *sha256)
{
	int		i;
	char	*output;

	i = 0;
	output = NULL;
	while (i < 8)
	{
		output = ft_strjoinf(output,
			prepend_zeros_to_hex(
				ulltoa_base("0123456789abcdef", sha256->status[i]), 8),
			3);
		i++;
	}
	return (output);
}

char		*convert_sha256(char *input, size_t size)
{
	char			*output;
	t_sha256		*sha256;

	if (!(sha256 = initialize_sha256_structure(input, size)))
		return (NULL);
	process_sha256(&sha256);
	output = convert_output(sha256);
	destroy_sha256_structure(sha256);
	return (output);
}

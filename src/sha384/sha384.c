/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:17:54 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 00:24:06 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*convert_output(t_sha384 *sha384)
{
	int		i;
	char	*output;

	i = 0;
	output = NULL;
	while (i < 6)
	{
		output = ft_strjoinf(output,
			prepend_zeros_to_hex(
				ulltoa_base("0123456789abcdef", sha384->status[i]), 16),
			3);
		i++;
	}
	return (output);
}

char		*convert_sha384(char *input, size_t size)
{
	char			*output;
	t_sha384		*sha384;

	if (!(sha384 = initialize_sha384_structure(input, size)))
		return (NULL);
	process_sha384(&sha384);
	output = convert_output(sha384);
	destroy_sha384_structure(sha384);
	return (output);
}

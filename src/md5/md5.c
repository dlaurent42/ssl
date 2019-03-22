/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:37 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/22 18:51:41 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*convert_hexa_with_precision(char *str)
{
	char	*zeros;
	size_t	length;

	zeros = NULL;
	length = ft_strlens(str);
	if (length == 8)
		return (str);
	if (!(zeros = (char *)ft_strnew(sizeof(char) * (8 - length + 1))))
		return (str);
	zeros = (char *)ft_memsets((void *)zeros, '0', 8 - length);
	return (ft_strjoinf(zeros, str, 3));
}

static char	*convert_output(t_md5 *md5)
{
	char	*output;

	output = ft_strdupf(convert_hexa_with_precision(
		ulltoa_base("0123456789abcdef", reverse_bits(md5->h0))));
	output = ft_strjoinf(output, convert_hexa_with_precision(
		ulltoa_base("0123456789abcdef", reverse_bits(md5->h1))), 3);
	output = ft_strjoinf(output, convert_hexa_with_precision(
		ulltoa_base("0123456789abcdef", reverse_bits(md5->h2))), 3);
	output = ft_strjoinf(output, convert_hexa_with_precision(
		ulltoa_base("0123456789abcdef", reverse_bits(md5->h3))), 3);
	return (output);
}

char		*convert_md5(char *input, size_t size)
{
	t_md5	*md5;
	char	*output;

	if (!(md5 = initialize_md5_structure(input, size)))
		return (NULL);
	process_md5(&md5);
	output = convert_output(md5);
	destroy_md5_structure(md5);
	return (output);
}

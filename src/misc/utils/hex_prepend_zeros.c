/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_prepend_zeros.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:11:32 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/25 14:12:09 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char	*prepend_zeros_to_hex(char *str)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnjoinsf1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:43:26 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/25 13:15:49 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char		*strnjoinsf1(char *s1, char *s2, size_t len1, size_t len2)
{
	size_t	i;
	char	*output;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!(output = (char *)ft_memalloc(sizeof(char) * (len1 + len2 + 1))))
	{
		(s1) ? ft_strdel(&s1) : NULL;
		return (NULL);
	}
	while (i < len1 || i < len2)
	{
		if (i < len1)
			output[i] = s1[i];
		if (i < len2)
			output[i + len1] = s2[i];
		i++;
	}
	(s1) ? ft_strdel(&s1) : NULL;
	return (output);
}

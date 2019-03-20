/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:35:45 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/20 13:41:27 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	print_memory(const char *str, size_t size)
{
	int			bit;
	int			j;
	size_t		i;

	i = 0;
	while (i < size)
	{
		j = -1;
		while (++j < 8)
		{
			bit = 8;
			while (--bit >= 0)
				((unsigned char)(str[i + j]) & (1 << bit))
					? write(1, "1", 1) : write(1, "0", 1);
			write(1, " ", 1);
		}
		j = -1;
		while (++j < 8)
			((unsigned char)str[i + j] > 32 && (unsigned char)str[i + j] < 128)
				? write(1, &str[i + j], 1) : write(1, ".", 1);
		write(1, "\n", 1);
		i += 8;
	}
}

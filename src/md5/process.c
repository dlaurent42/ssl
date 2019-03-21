/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:14:59 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/21 18:48:46 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void		md5_update_fg(t_md5 **md5, uint64_t i)
{
	if (i < 16)
	{
		(*md5)->f = ((*md5)->b & (*md5)->c) | ((!(*md5)->b) & (*md5)->d);
		(*md5)->g = i;
	}
	else if (i < 32)
	{
		(*md5)->f = ((*md5)->d & (*md5)->b) | ((!(*md5)->d) & (*md5)->c);
		(*md5)->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		(*md5)->f = (*md5)->b ^ (*md5)->c ^ (*md5)->d;
		(*md5)->g = (3 * i + 5) % 16;
	}
	else
	{
		(*md5)->f = (*md5)->c ^ ((*md5)->b | (!(*md5)->d));
		(*md5)->g = (7 * i) % 16;
	}
}

static void		md5_update_abcd_based_on_fg(t_md5 **md5, uint64_t i)
{
	uint32_t	temp;

	temp = (*md5)->d;
	(*md5)->d = (*md5)->c;
	(*md5)->c = (*md5)->b;
	(*md5)->b += rotate_left(
		((*md5)->a + (*md5)->f + g_md5_k[i]
			+ (((*md5)->padded_str[(*md5)->g] << 24)
			| ((*md5)->padded_str[(*md5)->g + 1] << 16)
			| ((*md5)->padded_str[(*md5)->g + 2] << 8)
			| (*md5)->padded_str[(*md5)->g + 3])),
		g_md5_r[i]);
	(*md5)->a = temp;
}

static void		md5_update_abcd(t_md5 **md5)
{
	(*md5)->a = (*md5)->h0;
	(*md5)->b = (*md5)->h1;
	(*md5)->c = (*md5)->h2;
	(*md5)->d = (*md5)->h3;
}

static void		md5_update_h0123(t_md5 **md5)
{
	(*md5)->h0 += (*md5)->a;
	(*md5)->h1 += (*md5)->b;
	(*md5)->h2 += (*md5)->c;
	(*md5)->h3 += (*md5)->d;
}

static void		md5_debug(t_md5 *md5)
{
	ft_printf("%.8x\n%.8x\n%.8x\n%.8x\n", reverse_bits(md5->h0),
		reverse_bits(md5->h1),
		reverse_bits(md5->h2), reverse_bits(md5->h3));
}

void		debug_md5(t_md5 *md5, char *message)
{
	ft_printf("%s\n", message);
	ft_printf("h0: %u\n", md5->h0);
	ft_printf("h1: %u\n", md5->h1);
	ft_printf("h2: %u\n", md5->h2);
	ft_printf("h3: %u\n", md5->h3);
	ft_printf("a: %u\n", md5->a);
	ft_printf("b: %u\n", md5->b);
	ft_printf("c: %u\n", md5->c);
	ft_printf("d: %u\n", md5->d);
}

char			*process_md5(t_md5 **md5)
{
	uint64_t i;
	uint64_t j;

	i = 0;
	ft_printf("%d\n", (*md5)->padded_str_length);
	while (i < (*md5)->padded_str_length)
	{
		j = 0;
		debug_md5(*md5, "Before init abcd");
		md5_update_abcd(md5);
		debug_md5(*md5, "After init abcd");
		while (j < 64)
		{
			md5_update_fg(md5, j);
			debug_md5(*md5, "After stages");
			md5_update_abcd_based_on_fg(md5, j);
			debug_md5(*md5, "After final abcd");
			j++;
		}
		debug_md5(*md5, "Before h");
		md5_update_h0123(md5);
		debug_md5(*md5, "After h");
		i += 64;
	}
	md5_debug(*md5);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:14:59 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/22 16:36:44 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void		md5_update_fg(t_md5 **md5, uint64_t i)
{
	if (i < 16)
	{
		(*md5)->f = ((*md5)->b & (*md5)->c) | ((~(*md5)->b) & (*md5)->d);
		(*md5)->g = i;
	}
	else if (i < 32)
	{
		(*md5)->f = ((*md5)->d & (*md5)->b) | ((~(*md5)->d) & (*md5)->c);
		(*md5)->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		(*md5)->f = (*md5)->b ^ (*md5)->c ^ (*md5)->d;
		(*md5)->g = (3 * i + 5) % 16;
	}
	else
	{
		(*md5)->f = (*md5)->c ^ ((*md5)->b | (~(*md5)->d));
		(*md5)->g = (7 * i) % 16;
	}
}

static void		md5_update_abcd_based_on_fg(t_md5 **md5, uint64_t i, uint64_t j)
{
	(*md5)->f += (*md5)->a + g_md5_k[j]
	+ (uint32_t)(((unsigned char)(*md5)->padded_str[(*md5)->g * 4
		+ (i / 64) * 64 + 3] << 24)
	| ((unsigned char)(*md5)->padded_str[(*md5)->g * 4
		+ (i / 64) * 64 + 2] << 16)
	| ((unsigned char)(*md5)->padded_str[(*md5)->g * 4
		+ (i / 64) * 64 + 1] << 8)
	| (unsigned char)(*md5)->padded_str[(*md5)->g * 4 + (i / 64) * 64 + 0]);
	(*md5)->a = (*md5)->d;
	(*md5)->d = (*md5)->c;
	(*md5)->c = (*md5)->b;
	(*md5)->b += rotate_left((*md5)->f, g_md5_r[j]);
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

void			process_md5(t_md5 **md5)
{
	uint64_t i;
	uint64_t j;

	i = 0;
	while (i < (*md5)->padded_str_length)
	{
		j = 0;
		md5_update_abcd(md5);
		while (j < 64)
		{
			md5_update_fg(md5, j);
			md5_update_abcd_based_on_fg(md5, i, j);
			j++;
		}
		md5_update_h0123(md5);
		i += 64;
	}
}

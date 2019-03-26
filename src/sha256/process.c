/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:15:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/26 14:44:35 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void		sha256_rotate(t_sha256 **sha256)
{
	int		x;

	x = 16;
	while (x < 64)
	{
		(*sha256)->tmp4 = rotate_right((*sha256)->w[x - 15], 7) ^
			rotate_right((*sha256)->w[x - 15], 18)
				^ ((*sha256)->w[x - 15] >> 3);
		(*sha256)->tmp = rotate_right((*sha256)->w[x - 2], 17) ^
			rotate_right((*sha256)->w[x - 2], 19)
				^ ((*sha256)->w[x - 2] >> 10);
		(*sha256)->w[x] = (*sha256)->w[x - 16] + (*sha256)->tmp4
			+ (*sha256)->w[x - 7] + (*sha256)->tmp;
		x++;
	}
}

static void		sha256_order_arr(t_sha256 **sha256, int i)
{
	if (!((*sha256)->w = (uint32_t *)ft_memalloc(512)))
		return ;
	ft_memcpy((*sha256)->w, &((*sha256)->hash32[i * 16]), 512);
	sha256_rotate(sha256);
	(*sha256)->a = (*sha256)->status[0];
	(*sha256)->b = (*sha256)->status[1];
	(*sha256)->c = (*sha256)->status[2];
	(*sha256)->d = (*sha256)->status[3];
	(*sha256)->e = (*sha256)->status[4];
	(*sha256)->f = (*sha256)->status[5];
	(*sha256)->g = (*sha256)->status[6];
	(*sha256)->h = (*sha256)->status[7];
}

static void		sha256_assemble(t_sha256 **sha256, int x)
{
	(*sha256)->tmp = rotate_right((*sha256)->e, 6)
		^ rotate_right((*sha256)->e, 11) ^
		rotate_right((*sha256)->e, 25);
	(*sha256)->tmp2 = ((*sha256)->e & (*sha256)->f)
		^ ((~(*sha256)->e) & (*sha256)->g);
	(*sha256)->tmp3 = (*sha256)->h + (*sha256)->tmp
		+ (*sha256)->tmp2 + g_sha256_k[x] + (*sha256)->w[x];
	(*sha256)->tmp4 = rotate_right((*sha256)->a, 2)
		^ rotate_right((*sha256)->a, 13)
		^ rotate_right((*sha256)->a, 22);
	(*sha256)->tmp5 = ((*sha256)->a & (*sha256)->b)
		^ ((*sha256)->a & (*sha256)->c) ^ ((*sha256)->b & (*sha256)->c);
	(*sha256)->tmp6 = (*sha256)->tmp4 + (*sha256)->tmp5;
	(*sha256)->h = (*sha256)->g;
	(*sha256)->g = (*sha256)->f;
	(*sha256)->f = (*sha256)->e;
	(*sha256)->e = (*sha256)->d + (*sha256)->tmp3;
	(*sha256)->d = (*sha256)->c;
	(*sha256)->c = (*sha256)->b;
	(*sha256)->b = (*sha256)->a;
	(*sha256)->a = (*sha256)->tmp3 + (*sha256)->tmp6;
}

void			process_sha256(t_sha256 **sha256)
{
	int		i;
	int		x;

	i = 0;
	while (i < (int)((*sha256)->offset))
	{
		sha256_order_arr(sha256, i);
		x = -1;
		while (++x < 64)
			sha256_assemble(sha256, x);
		(*sha256)->status[0] += (*sha256)->a;
		(*sha256)->status[1] += (*sha256)->b;
		(*sha256)->status[2] += (*sha256)->c;
		(*sha256)->status[3] += (*sha256)->d;
		(*sha256)->status[4] += (*sha256)->e;
		(*sha256)->status[5] += (*sha256)->f;
		(*sha256)->status[6] += (*sha256)->g;
		(*sha256)->status[7] += (*sha256)->h;
		free((*sha256)->w);
		(*sha256)->w = NULL;
		i++;
	}
	free((*sha256)->hash32);
	(*sha256)->hash32 = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:15:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 17:46:06 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static uint64_t	sha256_get_temp(t_sha256 **sha256, int temp_num, int i)
{
	uint64_t	s1;
	uint64_t	ch;
	uint64_t	s0;
	uint64_t	maj;

	if (temp_num == 1)
	{
		s1 = rotate_right((*sha256)->e, 6)
			^ rotate_right((*sha256)->e, 11)
			^ rotate_right((*sha256)->e, 25);
		ch = ((*sha256)->e & (*sha256)->f) ^ ((~(*sha256)->e) & (*sha256)->g);
		return ((*sha256)->h + s1 + ch + g_sha256_k[i] + (*sha256)->w[i]);
	}
	else
	{
		s0 = rotate_right((*sha256)->a, 2)
			^ rotate_right((*sha256)->a, 13)
			^ rotate_right((*sha256)->a, 22);
		maj = ((*sha256)->a & (*sha256)->b)
			^ ((*sha256)->a & (*sha256)->c)
			^ ((*sha256)->b & (*sha256)->c);
		return (s0 + maj);
	}
}

static void		sha256_compression_loop(t_sha256 **sha256, int i)
{
	uint64_t	temp1;
	uint64_t	temp2;

	temp1 = sha256_get_temp(sha256, 1, i);
	temp2 = sha256_get_temp(sha256, 2, i);
	(*sha256)->h = (*sha256)->g;
	(*sha256)->g = (*sha256)->f;
	(*sha256)->f = (*sha256)->e;
	(*sha256)->e = (*sha256)->d + temp1;
	(*sha256)->d = (*sha256)->c;
	(*sha256)->c = (*sha256)->b;
	(*sha256)->b = (*sha256)->a;
	(*sha256)->a = temp1 + temp2;
}

static void		sha256_create_schedule_array(t_sha256 **sha256, uint64_t i)
{
	int			j;
	uint64_t	s0;
	uint64_t	s1;

	j = -1;
	if (!((*sha256)->w = (uint32_t *)ft_memalloc(64 * sizeof(uint32_t))))
		return ;
	while (++j < 16)
	{
		(*sha256)->w[j] = (uint32_t)(
			(uint32_t)((unsigned char)((*sha256)->padded_str[i + 0]) << 24)
			| (uint32_t)((unsigned char)((*sha256)->padded_str[i + 1]) << 16)
			| (uint32_t)((unsigned char)((*sha256)->padded_str[i + 2]) << 8)
			| (uint32_t)((unsigned char)(*sha256)->padded_str[i + 3]));
		i += 4;
	}
	while (j < 64)
	{
		s0 = rotate_right((*sha256)->w[j - 15], 7)
		^ rotate_right((*sha256)->w[j - 15], 18) ^ ((*sha256)->w[j - 15] >> 3);
		s1 = rotate_right((*sha256)->w[j - 2], 17)
		^ rotate_right((*sha256)->w[j - 2], 19) ^ ((*sha256)->w[j - 2] >> 10);
		(*sha256)->w[j] = (*sha256)->w[j - 16] + s0 + (*sha256)->w[j - 7] + s1;
		j++;
	}
}

static void		sha256_initialize_working_variables(t_sha256 **sha256)
{
	(*sha256)->a = (*sha256)->status[0];
	(*sha256)->b = (*sha256)->status[1];
	(*sha256)->c = (*sha256)->status[2];
	(*sha256)->d = (*sha256)->status[3];
	(*sha256)->e = (*sha256)->status[4];
	(*sha256)->f = (*sha256)->status[5];
	(*sha256)->g = (*sha256)->status[6];
	(*sha256)->h = (*sha256)->status[7];
}

void			process_sha256(t_sha256 **sha256)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	while (i < (*sha256)->padded_str_length)
	{
		j = 0;
		sha256_create_schedule_array(sha256, i);
		sha256_initialize_working_variables(sha256);
		while (j < 64)
		{
			sha256_compression_loop(sha256, j);
			j++;
		}
		(*sha256)->status[0] += (*sha256)->a;
		(*sha256)->status[1] += (*sha256)->b;
		(*sha256)->status[2] += (*sha256)->c;
		(*sha256)->status[3] += (*sha256)->d;
		(*sha256)->status[4] += (*sha256)->e;
		(*sha256)->status[5] += (*sha256)->f;
		(*sha256)->status[6] += (*sha256)->g;
		(*sha256)->status[7] += (*sha256)->h;
		ft_memdel((void **)&(*sha256)->w);
		i += 64;
	}
}

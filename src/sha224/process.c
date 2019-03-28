/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:15:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 17:54:37 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static uint64_t	sha224_get_temp(t_sha224 **sha224, int temp_num, int i)
{
	uint64_t	s1;
	uint64_t	ch;
	uint64_t	s0;
	uint64_t	maj;

	if (temp_num == 1)
	{
		s1 = rotate_right((*sha224)->e, 6)
			^ rotate_right((*sha224)->e, 11)
			^ rotate_right((*sha224)->e, 25);
		ch = ((*sha224)->e & (*sha224)->f) ^ ((~(*sha224)->e) & (*sha224)->g);
		return ((*sha224)->h + s1 + ch + g_sha224_k[i] + (*sha224)->w[i]);
	}
	else
	{
		s0 = rotate_right((*sha224)->a, 2)
			^ rotate_right((*sha224)->a, 13)
			^ rotate_right((*sha224)->a, 22);
		maj = ((*sha224)->a & (*sha224)->b)
			^ ((*sha224)->a & (*sha224)->c)
			^ ((*sha224)->b & (*sha224)->c);
		return (s0 + maj);
	}
}

static void		sha224_compression_loop(t_sha224 **sha224, int i)
{
	uint64_t	temp1;
	uint64_t	temp2;

	temp1 = sha224_get_temp(sha224, 1, i);
	temp2 = sha224_get_temp(sha224, 2, i);
	(*sha224)->h = (*sha224)->g;
	(*sha224)->g = (*sha224)->f;
	(*sha224)->f = (*sha224)->e;
	(*sha224)->e = (*sha224)->d + temp1;
	(*sha224)->d = (*sha224)->c;
	(*sha224)->c = (*sha224)->b;
	(*sha224)->b = (*sha224)->a;
	(*sha224)->a = temp1 + temp2;
}

static void		sha224_create_schedule_array(t_sha224 **sha224, uint64_t i)
{
	int			j;
	uint64_t	s0;
	uint64_t	s1;

	j = -1;
	if (!((*sha224)->w = (uint32_t *)ft_memalloc(64 * sizeof(uint32_t))))
		return ;
	while (++j < 16)
	{
		(*sha224)->w[j] = (uint32_t)(
			(uint32_t)((unsigned char)((*sha224)->padded_str[i + 0]) << 24)
			| (uint32_t)((unsigned char)((*sha224)->padded_str[i + 1]) << 16)
			| (uint32_t)((unsigned char)((*sha224)->padded_str[i + 2]) << 8)
			| (uint32_t)((unsigned char)(*sha224)->padded_str[i + 3]));
		i += 4;
	}
	while (j < 64)
	{
		s0 = rotate_right((*sha224)->w[j - 15], 7)
		^ rotate_right((*sha224)->w[j - 15], 18) ^ ((*sha224)->w[j - 15] >> 3);
		s1 = rotate_right((*sha224)->w[j - 2], 17)
		^ rotate_right((*sha224)->w[j - 2], 19) ^ ((*sha224)->w[j - 2] >> 10);
		(*sha224)->w[j] = (*sha224)->w[j - 16] + s0 + (*sha224)->w[j - 7] + s1;
		j++;
	}
}

static void		sha224_initialize_working_variables(t_sha224 **sha224)
{
	(*sha224)->a = (*sha224)->status[0];
	(*sha224)->b = (*sha224)->status[1];
	(*sha224)->c = (*sha224)->status[2];
	(*sha224)->d = (*sha224)->status[3];
	(*sha224)->e = (*sha224)->status[4];
	(*sha224)->f = (*sha224)->status[5];
	(*sha224)->g = (*sha224)->status[6];
	(*sha224)->h = (*sha224)->status[7];
}

void			process_sha224(t_sha224 **sha224)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	while (i < (*sha224)->padded_str_length)
	{
		j = 0;
		sha224_create_schedule_array(sha224, i);
		sha224_initialize_working_variables(sha224);
		while (j < 64)
		{
			sha224_compression_loop(sha224, j);
			j++;
		}
		(*sha224)->status[0] += (*sha224)->a;
		(*sha224)->status[1] += (*sha224)->b;
		(*sha224)->status[2] += (*sha224)->c;
		(*sha224)->status[3] += (*sha224)->d;
		(*sha224)->status[4] += (*sha224)->e;
		(*sha224)->status[5] += (*sha224)->f;
		(*sha224)->status[6] += (*sha224)->g;
		(*sha224)->status[7] += (*sha224)->h;
		ft_memdel((void **)&(*sha224)->w);
		i += 64;
	}
}

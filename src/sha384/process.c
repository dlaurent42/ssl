/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:15:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 00:23:45 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static uint64_t	sha384_get_temp(t_sha384 **sha384, int temp_num, int i)
{
	uint64_t	s1;
	uint64_t	ch;
	uint64_t	s0;
	uint64_t	maj;

	if (temp_num == 1)
	{
		s1 = rotate_right64((*sha384)->e, 14)
			^ rotate_right64((*sha384)->e, 18)
			^ rotate_right64((*sha384)->e, 41);
		ch = ((*sha384)->e & (*sha384)->f) ^ ((~(*sha384)->e) & (*sha384)->g);
		return ((*sha384)->h + s1 + ch + g_sha384_k[i] + (*sha384)->w[i]);
	}
	else
	{
		s0 = rotate_right64((*sha384)->a, 28)
			^ rotate_right64((*sha384)->a, 34)
			^ rotate_right64((*sha384)->a, 39);
		maj = ((*sha384)->a & (*sha384)->b)
			^ ((*sha384)->a & (*sha384)->c)
			^ ((*sha384)->b & (*sha384)->c);
		return (s0 + maj);
	}
}

static void		sha384_compression_loop(t_sha384 **sha384, int i)
{
	uint64_t	temp1;
	uint64_t	temp2;

	temp1 = sha384_get_temp(sha384, 1, i);
	temp2 = sha384_get_temp(sha384, 2, i);
	(*sha384)->h = (*sha384)->g;
	(*sha384)->g = (*sha384)->f;
	(*sha384)->f = (*sha384)->e;
	(*sha384)->e = (*sha384)->d + temp1;
	(*sha384)->d = (*sha384)->c;
	(*sha384)->c = (*sha384)->b;
	(*sha384)->b = (*sha384)->a;
	(*sha384)->a = temp1 + temp2;
}

static void		sha384_create_schedule_array(t_sha384 **sha384, uint64_t i)
{
	int			j;
	uint64_t	s0;
	uint64_t	s1;

	j = -1;
	if (!((*sha384)->w = (uint64_t *)ft_memalloc(80 * sizeof(uint64_t))))
		return ;
	while (++j < 16)
	{
		sha384_char_to_uint64(sha384, i, j);
		i += 8;
	}
	while (j < 80)
	{
		s0 = rotate_right64((*sha384)->w[j - 15], 1)
			^ rotate_right64((*sha384)->w[j - 15], 8)
			^ ((*sha384)->w[j - 15] >> 7);
		s1 = rotate_right64((*sha384)->w[j - 2], 19)
			^ rotate_right64((*sha384)->w[j - 2], 61)
			^ ((*sha384)->w[j - 2] >> 6);
		(*sha384)->w[j] = (*sha384)->w[j - 16] + s0 + (*sha384)->w[j - 7] + s1;
		j++;
	}
}

static void		sha384_initialize_working_variables(t_sha384 **sha384)
{
	(*sha384)->a = (*sha384)->status[0];
	(*sha384)->b = (*sha384)->status[1];
	(*sha384)->c = (*sha384)->status[2];
	(*sha384)->d = (*sha384)->status[3];
	(*sha384)->e = (*sha384)->status[4];
	(*sha384)->f = (*sha384)->status[5];
	(*sha384)->g = (*sha384)->status[6];
	(*sha384)->h = (*sha384)->status[7];
}

void			process_sha384(t_sha384 **sha384)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	while (i < (*sha384)->padded_str_length)
	{
		j = 0;
		sha384_create_schedule_array(sha384, i);
		sha384_initialize_working_variables(sha384);
		while (j < 80)
		{
			sha384_compression_loop(sha384, j);
			j++;
		}
		(*sha384)->status[0] += (*sha384)->a;
		(*sha384)->status[1] += (*sha384)->b;
		(*sha384)->status[2] += (*sha384)->c;
		(*sha384)->status[3] += (*sha384)->d;
		(*sha384)->status[4] += (*sha384)->e;
		(*sha384)->status[5] += (*sha384)->f;
		(*sha384)->status[6] += (*sha384)->g;
		(*sha384)->status[7] += (*sha384)->h;
		ft_memdel((void **)&(*sha384)->w);
		i += 128;
	}
}

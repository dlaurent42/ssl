/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:15:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 00:02:38 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static uint64_t	sha512_get_temp(t_sha512 **sha512, int temp_num, int i)
{
	uint64_t	s1;
	uint64_t	ch;
	uint64_t	s0;
	uint64_t	maj;

	if (temp_num == 1)
	{
		s1 = rotate_right64((*sha512)->e, 14)
			^ rotate_right64((*sha512)->e, 18)
			^ rotate_right64((*sha512)->e, 41);
		ch = ((*sha512)->e & (*sha512)->f) ^ ((~(*sha512)->e) & (*sha512)->g);
		return ((*sha512)->h + s1 + ch + g_sha512_k[i] + (*sha512)->w[i]);
	}
	else
	{
		s0 = rotate_right64((*sha512)->a, 28)
			^ rotate_right64((*sha512)->a, 34)
			^ rotate_right64((*sha512)->a, 39);
		maj = ((*sha512)->a & (*sha512)->b)
			^ ((*sha512)->a & (*sha512)->c)
			^ ((*sha512)->b & (*sha512)->c);
		return (s0 + maj);
	}
}

static void		sha512_compression_loop(t_sha512 **sha512, int i)
{
	uint64_t	temp1;
	uint64_t	temp2;

	temp1 = sha512_get_temp(sha512, 1, i);
	temp2 = sha512_get_temp(sha512, 2, i);
	(*sha512)->h = (*sha512)->g;
	(*sha512)->g = (*sha512)->f;
	(*sha512)->f = (*sha512)->e;
	(*sha512)->e = (*sha512)->d + temp1;
	(*sha512)->d = (*sha512)->c;
	(*sha512)->c = (*sha512)->b;
	(*sha512)->b = (*sha512)->a;
	(*sha512)->a = temp1 + temp2;
}

static void		sha512_create_schedule_array(t_sha512 **sha512, uint64_t i)
{
	int			j;
	uint64_t	s0;
	uint64_t	s1;

	j = -1;
	if (!((*sha512)->w = (uint64_t *)ft_memalloc(80 * sizeof(uint64_t))))
		return ;
	while (++j < 16)
	{
		sha512_char_to_uint64(sha512, i, j);
		i += 8;
	}
	while (j < 80)
	{
		s0 = rotate_right64((*sha512)->w[j - 15], 1)
			^ rotate_right64((*sha512)->w[j - 15], 8)
			^ ((*sha512)->w[j - 15] >> 7);
		s1 = rotate_right64((*sha512)->w[j - 2], 19)
			^ rotate_right64((*sha512)->w[j - 2], 61)
			^ ((*sha512)->w[j - 2] >> 6);
		(*sha512)->w[j] = (*sha512)->w[j - 16] + s0 + (*sha512)->w[j - 7] + s1;
		j++;
	}
}

static void		sha512_initialize_working_variables(t_sha512 **sha512)
{
	(*sha512)->a = (*sha512)->status[0];
	(*sha512)->b = (*sha512)->status[1];
	(*sha512)->c = (*sha512)->status[2];
	(*sha512)->d = (*sha512)->status[3];
	(*sha512)->e = (*sha512)->status[4];
	(*sha512)->f = (*sha512)->status[5];
	(*sha512)->g = (*sha512)->status[6];
	(*sha512)->h = (*sha512)->status[7];
}

void			process_sha512(t_sha512 **sha512)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	while (i < (*sha512)->padded_str_length)
	{
		j = 0;
		sha512_create_schedule_array(sha512, i);
		sha512_initialize_working_variables(sha512);
		while (j < 80)
		{
			sha512_compression_loop(sha512, j);
			j++;
		}
		(*sha512)->status[0] += (*sha512)->a;
		(*sha512)->status[1] += (*sha512)->b;
		(*sha512)->status[2] += (*sha512)->c;
		(*sha512)->status[3] += (*sha512)->d;
		(*sha512)->status[4] += (*sha512)->e;
		(*sha512)->status[5] += (*sha512)->f;
		(*sha512)->status[6] += (*sha512)->g;
		(*sha512)->status[7] += (*sha512)->h;
		ft_memdel((void **)&(*sha512)->w);
		i += 128;
	}
}

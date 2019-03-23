/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:21:46 by azaliaus          #+#    #+#             */
/*   Updated: 2019/03/23 21:11:32 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

const uint32_t g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void	sha256_order_arr(t_sha *sha, int i)
{
	if (!(sha->w = (uint32_t *)ft_memalloc(512)))
		return ;
	ft_memcpy(sha->w, &sha->hash32[i * 16], 16 * 32);
	sha_rotate(sha);
	sha->a = sha->status[0];
	sha->b = sha->status[1];
	sha->c = sha->status[2];
	sha->d = sha->status[3];
	sha->e = sha->status[4];
	sha->f = sha->status[5];
	sha->g = sha->status[6];
	sha->h = sha->status[7];
}

static void	sha256_assemble(t_sha *sha, int x)
{
	sha->tmp = sha_rrotate(sha->e, 6) ^ sha_rrotate(sha->e, 11) ^
				sha_rrotate(sha->e, 25);
	sha->tmp2 = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
	sha->tmp3 = sha->h + sha->tmp + sha->tmp2 + g_k[x] + sha->w[x];
	sha->tmp4 = sha_rrotate(sha->a, 2) ^ sha_rrotate(sha->a, 13) ^
				sha_rrotate(sha->a, 22);
	sha->tmp5 = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
	sha->tmp6 = sha->tmp4 + sha->tmp5;
	sha->h = sha->g;
	sha->g = sha->f;
	sha->f = sha->e;
	sha->e = sha->d + sha->tmp3;
	sha->d = sha->c;
	sha->c = sha->b;
	sha->b = sha->a;
	sha->a = sha->tmp3 + sha->tmp6;
}

static void	sha256_cryper(t_sha *sha)
{
	int		i;
	int		x;

	i = 0;
	while (i < (int)(sha->offset))
	{
		sha256_order_arr(sha, i);
		x = -1;
		while (++x < 64)
			sha256_assemble(sha, x);
		sha->status[0] += sha->a;
		sha->status[1] += sha->b;
		sha->status[2] += sha->c;
		sha->status[3] += sha->d;
		sha->status[4] += sha->e;
		sha->status[5] += sha->f;
		sha->status[6] += sha->g;
		sha->status[7] += sha->h;
		free(sha->w);
		i++;
	}
	free(sha->hash32);
}

char		*sha256_crypt(char *input)
{
	t_sha		sha;
	int			len;
	int			i;

	i = 0;
	sha256_init(&sha);
	len = ft_strlen(input);
	sha.len = len * 8;
	sha.offset = (((sha.len + 16 + 64) / 512) + 1);
	if(!(sha.hash32 = (uint32_t *)ft_memalloc(sha.offset * 16 * 4)))
		return (NULL);
	ft_strcpy((char *)sha.hash32, input);
	((char *)sha.hash32)[len] = 0x80; // int = 128
	while (i < ((int)sha.offset * 16) - 1) // optimize | looks like garbage
	{
		sha.hash32[i] = ((sha.hash32[i] >> 24) |
			((sha.hash32[i] & 0xff0000) >> 8) |
			((sha.hash32[i] & 0xff00) << 8) | (sha.hash32[i] << 24));
		i++;
	}
	sha.hash32[((sha.offset * 512 - 64) / 32) + 1] = sha.len;
	sha256_cryper(&sha);
	return (sha256_convert(&sha));
}

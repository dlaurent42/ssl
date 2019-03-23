/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:52:50 by azaliaus          #+#    #+#             */
/*   Updated: 2019/03/23 21:29:53 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t	sha_rrotate(uint32_t x, uint32_t n)
{
	return ((((unsigned int)x >> n)) | (x << (32 - n)));
}

void		sha_rotate(t_sha *sha)
{
	int		x;

	x = 16;
	while (x < 64)
	{
		sha->tmp4 = sha_rrotate(sha->w[x - 15], 7) ^
				sha_rrotate(sha->w[x - 15], 18) ^ (sha->w[x - 15] >> 3);
		sha->tmp = sha_rrotate(sha->w[x - 2], 17) ^
				sha_rrotate(sha->w[x - 2], 19) ^ (sha->w[x - 2] >> 10);
		sha->w[x] = sha->w[x - 16] + sha->tmp4 + sha->w[x - 7] + sha->tmp;
		x++;
	}
}

void		sha256_init(t_sha *sha)
{
	sha->status[0] = 0x6a09e667;
	sha->status[1] = 0xbb67ae85;
	sha->status[2] = 0x3c6ef372;
	sha->status[3] = 0xa54ff53a;
	sha->status[4] = 0x510e527f;
	sha->status[5] = 0x9b05688c;
	sha->status[6] = 0x1f83d9ab;
	sha->status[7] = 0x5be0cd19;
	sha->len = 0;
}

static char	*sha_convert_hex(uint32_t hex)
{
	char	*ret;
	char	*base;
	int		len;

	if (!(ret = (char *)ft_memalloc(sizeof(char *) * 9)))
		return (NULL);
	ft_memset(ret, '0', 8);
	base = lltoa_base("0123456789abcdef", hex);
	len = 8 - ft_strlen(base);
	ft_strcpy(ret + len, base);
	ft_strdel(&base);
	return (ret);
}

char		*sha256_convert(t_sha *sha)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (i < 8)
	{
		ret = ft_strjoinf(ret, sha_convert_hex(sha->status[i]), 3);
		i++;
	}
	return (ret);
}

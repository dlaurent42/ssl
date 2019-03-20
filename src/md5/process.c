/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:14:59 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/20 15:45:43 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static uint32_t	r[64] = {
	7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
	5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
	4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
	6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};

static uint32_t	k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

// //initialiser les valeurs de hachage :
// var entier a := h0
// var entier b := h1
// var entier c := h2
// var entier d := h3

// //Boucle principale :
// pour i de 0 à 63 faire
//     si 0 ≤ i ≤ 15 alors
//           f := (b et c) ou ((non b) et d)
//           g := i
//     sinon si 16 ≤ i ≤ 31 alors
//           f := (d et b) ou ((non d) et c)
//           g := (5×i + 1) mod 16
//     sinon si 32 ≤ i ≤ 47 alors
//           f := b xor c xor d
//           g := (3×i + 5) mod 16
//     sinon si 48 ≤ i ≤ 63 alors
//         f := c xor (b ou (non d))
//         g := (7×i) mod 16
//     fin si
//     var entier temp := d
//     d := c
//     c := b
//     b := ((a + f + k[i] + w[g]) leftrotate r[i]) + b
//     a := temp
// fin pour

// //ajouter le résultat au bloc précédent :
// h0 := h0 + a
// h1 := h1 + b 
// h2 := h2 + c
// h3 := h3 + d

static void		md5_loop_execution(t_md5 **md5, unsigned long long i)
{
	unsigned long long	temp;

	if (i < 16)
		(*md5)->f = ((*md5)->b & (*md5)->c) | ((!(*md5)->b) & (*md5)->d);
	else if (i < 32)
		(*md5)->f = ((*md5)->d & (*md5)->b) | ((!(*md5)->d) & (*md5)->c);
	else if (i < 48)
		(*md5)->f = (*md5)->b ^ (*md5)->c ^ (*md5)->d;
	else
		(*md5)->f = (*md5)->c ^ ((*md5)->b | (!(*md5)->d));
	if (i < 16)
		(*md5)->g = i;
	else if (i < 32)
		(*md5)->g = (5 * i + 1) % 16;
	else if (i < 48)
		(*md5)->g = (3 * i + 5) % 16;
	else
		(*md5)->g = (7 * i) % 16;
	temp = (*md5)->d;
	(*md5)->d = (*md5)->c;
	(*md5)->c = (*md5)->b;
	(*md5)->b += left_rotate(
		((*md5)->a + (*md5)->f + k[i] + (*md5)->padded_str[(*md5)->g]), r[i]);
	(*md5)->a = temp;
}

char			*process_md5(t_md5 **md5)
{
	unsigned long long i;
	unsigned long long j;
	unsigned long long k;

	i = 0;
	while (i < (*md5)->padded_str_length)
	{
		j = 0;
		while (j < 16)
		{
			k = 0;
			(*md5)->a = (*md5)->h0;
			(*md5)->b = (*md5)->h1;
			(*md5)->c = (*md5)->h2;
			(*md5)->d = (*md5)->h3;
			while (k < 64)
			{
				md5_loop_execution(md5, k);
				k++;
			}
			(*md5)->h0 += (*md5)->a;
			(*md5)->h1 += (*md5)->b;
			(*md5)->h2 += (*md5)->c;
			(*md5)->h3 += (*md5)->d;
			j++;
			i += 4;
		}
	}
	printf("%u\n", (*md5)->h0);
	printf("%u\n", (*md5)->h1);
	printf("%u\n", (*md5)->h2);
	printf("%u\n", (*md5)->h3);
	printf("%s\n", ulltoa_base("0123456789abcdef", (*md5)->h0));
	printf("%s\n", ulltoa_base("0123456789abcdef", (*md5)->h1));
	printf("%s\n", ulltoa_base("0123456789abcdef", (*md5)->h2));
	printf("%s\n", ulltoa_base("0123456789abcdef", (*md5)->h3));
	return (NULL);
}
// d3b07384
// d113edec
// 49eaa623
// 8ad5ff00
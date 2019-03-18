/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:37 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 18:28:42 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/*
**
**		FROM WIKIPEDIA FR
**
** //Note : Toutes les variables sont sur 32 bits
** 
** //Définir r comme suit : 
** var entier[64] r, k
** r[ 0..15] := {7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22}
** r[16..31] := {5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20}
** r[32..47] := {4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23}
** r[48..63] := {6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21}
** 
** //MD5 utilise des sinus d'entiers pour ses constantes :
** pour i de 0 à 63 faire
**     k[i] := floor(abs(sin(i + 1)) × 2^32)
** fin pour
** 
** //Préparation des variables :
** var entier h0 := 0x67452301
** var entier h1 := 0xEFCDAB89
** var entier h2 := 0x98BADCFE
** var entier h3 := 0x10325476
** 
** //Préparation du message (padding) :
** ajouter le bit "1" au message
** ajouter le bit "0" jusqu'à ce que la taille du message en bits soit égale à 448 (mod 512)
** ajouter la taille du message initial(avant le padding) codée en 64-bit little-endian au message
** 
** //Découpage en blocs de 512 bits :
** pour chaque bloc de 512 bits du message
**     subdiviser en 16 mots de 32 bits en little-endian w[i], 0 ≤ i ≤ 15
** 
**     //initialiser les valeurs de hachage :
**     var entier a := h0
**     var entier b := h1
**     var entier c := h2
**     var entier d := h3
** 
**     //Boucle principale :
**     pour i de 0 à 63 faire
**         si 0 ≤ i ≤ 15 alors
**               f := (b et c) ou ((non b) et d)
**               g := i
**         sinon si 16 ≤ i ≤ 31 alors
**               f := (d et b) ou ((non d) et c)
**               g := (5×i + 1) mod 16
**         sinon si 32 ≤ i ≤ 47 alors
**               f := b xor c xor d
**               g := (3×i + 5) mod 16
**         sinon si 48 ≤ i ≤ 63 alors
**             f := c xor (b ou (non d))
**             g := (7×i) mod 16
**         fin si
**         var entier temp := d
**         d := c
**         c := b
**         b := ((a + f + k[i] + w[g]) leftrotate r[i]) + b
**         a := temp
**     fin pour
** 
**     //ajouter le résultat au bloc précédent :
**     h0 := h0 + a
**     h1 := h1 + b 
**     h2 := h2 + c
**     h3 := h3 + d
** fin pour
** 
** var entier empreinte := h0 concaténer h1 concaténer h2 concaténer h3 //(en little-endian)
*/

static uint32_t	r(void)
{
	uint32_t	r[64] = {
		7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
		5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
		4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
		6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
	};
	return (r);
}

static uint32_t	k(void)
{
	uint32_t	k[64] = {
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
	return (k);
}

static unsigned long long	strlenu(const char *message)
{
	int					i;
	unsigned long long	len;

	i = 0;
	len = 0;
	if (!message)
		return (len);
	while (message[i])
	{
		if ((unsigned char)message[i] < 0b10000000
		|| (unsigned char)message[i] >= 0b11000000)
			len++;
		i++;
	}
	return (len);
}

static char	*prepare_message(char *message)
{
	char				*new;
	unsigned long long	len;
	unsigned long long	full;

	len = strlenu(message);
	full = len + 1 + (512 - (len + 1) % 512);
	if (!(new = (char *)ft_memalloc(len)))
		return (NULL);
}

static char	*footprint_block(uint32_t *r, uint32_t *k, uint32_t *block)
{

}

char		*convert_md5(char *input)
{
	char	*output;

	(void)input;
	if (!(output = ft_strdups("MD5 hashed string")))
		return (NULL);
	return (output);
}

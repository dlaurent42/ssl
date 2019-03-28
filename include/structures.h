/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:50 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/27 18:58:46 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct				s_md5
{
	uint32_t				h0;
	uint32_t				h1;
	uint32_t				h2;
	uint32_t				h3;
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	uint64_t				f;
	uint64_t				g;
	char					*padded_str;
	uint64_t				initial_length;
	uint64_t				padded_str_length;
}							t_md5;

typedef struct				s_sha256
{
	uint32_t				status[8];
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	uint32_t				e;
	uint32_t				f;
	uint32_t				g;
	uint32_t				h;
	unsigned int			len;
	unsigned int			offset;
	uint32_t				*hash32;
	uint32_t				*w;
	uint32_t				tmp;
	uint32_t				tmp1;
	uint32_t				tmp2;
	uint32_t				tmp3;
	uint32_t				tmp4;
	uint32_t				tmp5;
	uint32_t				tmp6;
}							t_sha256;

typedef struct				s_ssl
{
	char					*hash_type;
	char					*input;
	char					*output;
	size_t					input_size;
	int						error;
	unsigned char			is_executed		:1;
	unsigned char			option_r		:1;
	unsigned char			option_q		:1;
	unsigned char			option_p		:1;
	unsigned char			empty			:4;
}							t_ssl;

#endif

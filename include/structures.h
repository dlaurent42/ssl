/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:50 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 01:42:10 by dlaurent         ###   ########.fr       */
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

typedef struct				s_sha224
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
	char					*padded_str;
	uint64_t				initial_length;
	uint64_t				padded_str_length;
	uint32_t				*w;
}							t_sha224;

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
	char					*padded_str;
	uint64_t				initial_length;
	uint64_t				padded_str_length;
	uint32_t				*w;
}							t_sha256;

typedef struct				s_sha384
{
	uint64_t				status[8];
	uint64_t				a;
	uint64_t				b;
	uint64_t				c;
	uint64_t				d;
	uint64_t				e;
	uint64_t				f;
	uint64_t				g;
	uint64_t				h;
	char					*padded_str;
	uint64_t				initial_length;
	uint64_t				padded_str_length;
	uint64_t				*w;
}							t_sha384;

typedef struct				s_sha512
{
	uint64_t				status[8];
	uint64_t				a;
	uint64_t				b;
	uint64_t				c;
	uint64_t				d;
	uint64_t				e;
	uint64_t				f;
	uint64_t				g;
	uint64_t				h;
	char					*padded_str;
	uint64_t				initial_length;
	uint64_t				padded_str_length;
	uint64_t				*w;
}							t_sha512;

typedef struct				s_dispatcher
{
	char					*name;
	char					*full_name;
	char					*(*dispatch)(char *input, size_t size);
}							t_dispatcher;

typedef struct				s_ssl
{
	char					*input;
	char					*output;
	size_t					input_size;
	int						error;
	unsigned char			hash_index;
	unsigned char			is_executed		:1;
	unsigned char			return_status	:1;
	unsigned char			option_r		:1;
	unsigned char			option_q		:1;
	unsigned char			option_p		:1;
	unsigned char			from_file		:1;
	unsigned char			from_stdin		:1;
	unsigned char			from_string		:1;
}							t_ssl;

#endif

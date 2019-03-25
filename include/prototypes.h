/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:49 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/25 14:46:48 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ssl.h"

/*
**********************************    MD5    ***********************************
**				It contains all prototypes relative to md5 hash
*/
char				*convert_md5(char *input, size_t size);
void				process_md5(t_md5 **md5);
t_md5				*initialize_md5_structure(char *input, size_t size);
void				destroy_md5_structure(t_md5 *md5);
char				*prepare_md5_padded_message(
						char *message,
						unsigned long long len,
						unsigned long long padded_len);

/*
********************************    SHA256    **********************************
**			  It contains all prototypes relative to sha256 hash
*/
char				*convert_sha256(char *input, size_t size);
t_sha256			*initialize_sha256_structure(char *input, size_t size);
void				destroy_sha256_structure(t_sha256 *sha256);
void				process_sha256(t_sha256 **sha256);
uint32_t			*prepare_sha256_padded_message(
						char *message,
						unsigned long long len,
						unsigned long long offset);

/*
*********************************    MISC    ***********************************
**		It contains all other prototypes non-relative to hash functions
*/

/*
**	DISPATCHER:	dispatch the program following hash asked by user
*/
void				dispatcher(t_ssl **ssl);

/*
**	DISPLAY:	handles output of the program in case of successful execution
*/
void				display(t_ssl *ssl);

/*
**	ERRORS:		handle every single fatal error in the program
*/
void				err_handler(unsigned char errcode, t_ssl *ssl);

/*
**	MEMORY:		cares about memory allocation and free of program's structures
*/
void				free_ssl(t_ssl *ssl);
void				declare_new_argument(
						t_ssl **ssl,
						char *arg,
						char type,
						size_t size);
t_ssl				*declare_empty_ssl_structure(void);

/*
**	PARSER:		parse arguments and fill t_ssl structure
*/
void				parse_arguments(t_ssl **ssl, char **av);
void				read_from_file(t_ssl *ssl, t_argument *arg);
void				read_from_stdin(t_ssl **ssl);

/*
**	UTILS:		contains all functions common to any hash
*/
uint32_t			rotate_left(uint32_t x, uint32_t c);
uint32_t			rotate_right(uint32_t x, uint32_t c);
uint32_t			reverse_bits(uint32_t value);
void				print_memory(const char *str, size_t size);
unsigned long long	strlenu(const char *message);
char				*strnjoinsf1(char *s1, char *s2, size_t len1, size_t len2);
char				*prepend_zeros_to_hex(char *str);

#endif

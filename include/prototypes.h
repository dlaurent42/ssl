/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:49 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 20:01:42 by dlaurent         ###   ########.fr       */
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
						char *msg,
						uint64_t len,
						uint64_t plen);

/*
********************************    SHA224    **********************************
**			  It contains all prototypes relative to sha224 hash
*/
char				*convert_sha224(char *input, size_t size);
t_sha224			*initialize_sha224_structure(char *input, size_t size);
void				destroy_sha224_structure(t_sha224 *sha224);
void				process_sha224(t_sha224 **sha224);
char				*prepare_sha224_padded_message(
						char *msg,
						uint64_t len,
						uint64_t plen);

/*
********************************    SHA256    **********************************
**			  It contains all prototypes relative to sha256 hash
*/
char				*convert_sha256(char *input, size_t size);
t_sha256			*initialize_sha256_structure(char *input, size_t size);
void				destroy_sha256_structure(t_sha256 *sha256);
void				process_sha256(t_sha256 **sha256);
char				*prepare_sha256_padded_message(
						char *msg,
						uint64_t len,
						uint64_t plen);

/*
********************************    SHA512    **********************************
**			  It contains all prototypes relative to sha512 hash
*/
char				*convert_sha512(char *input, size_t size);
t_sha512			*initialize_sha512_structure(char *input, size_t size);
void				destroy_sha512_structure(t_sha512 *sha512);
void				process_sha512(t_sha512 **sha512);
char				*prepare_sha512_padded_message(
						char *msg,
						uint64_t len,
						uint64_t plen);

/*
*********************************    MISC    ***********************************
**		It contains all other prototypes non-relative to hash functions
*/

/*
**	EXECUTION:	handles execution loop
*/
void				display(t_ssl **ssl, char *filename);
void				execute_hash(t_ssl **ssl, char **av);
void				execute_next_argument(t_ssl **ssl, int *i, char **av);
void				execute_from_string(t_ssl **ssl, char *s);
void				execute_from_file(t_ssl **ssl, char *filename);
void				execute_from_stdin(t_ssl **ssl);
void				execute_from_nothing(t_ssl **ssl);
void				read_from_file(t_ssl **ssl, char *filename);
void				read_from_stdin(t_ssl **ssl);

/*
**	ERRORS:		handle every single fatal error in the program
*/
void				err_handler(unsigned char errcode, t_ssl *ssl);

/*
**	MEMORY:		cares about memory allocation and free of program's structures
*/
void				free_ssl(t_ssl *ssl);
void				reset_ssl_structure(t_ssl **ssl);
t_ssl				*declare_empty_ssl_structure(void);

/*
**	UTILS:		contains all functions common to any hash
*/
uint32_t			rotate_left(uint32_t x, uint32_t c);
uint32_t			rotate_right(uint32_t x, uint32_t c);
uint32_t			reverse_bits(uint32_t value);
uint64_t			rotate_left64(uint64_t x, uint64_t c);
uint64_t			rotate_right64(uint64_t x, uint64_t c);
uint64_t			reverse_bits64(uint64_t value);
void				print_memory(const char *str, size_t size);
char				*strnjoinsf1(char *s1, char *s2, size_t len1, size_t len2);
char				*prepend_zeros_to_hex(char *str, size_t len);
bool				stdin_input_available(void);

#endif

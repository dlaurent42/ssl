/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:49 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/25 13:52:51 by dlaurent         ###   ########.fr       */
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
char				*prepare_padded_message(
						char *message,
						unsigned long long len,
						unsigned long long padded_len);

/*
********************************    SHA256    **********************************
**			  It contains all prototypes relative to sha256 hash
*/
char			*convert_sha256(char *input);
char			*sha256_crypt(char *input);
uint32_t		sha_rrotate(uint32_t x, uint32_t n);
void			sha_rotate(t_sha *sha);
void			sha256_init(t_sha *sha);
char			*sha256_convert(t_sha *sha);

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
uint32_t			reverse_bits(uint32_t value);
void				print_memory(const char *str, size_t size);
unsigned long long	strlenu(const char *message);
char				*strnjoins(char *s1, char *s2, size_t len1, size_t len2);
char				*strnjoinsf1(char *s1, char *s2, size_t len1, size_t len2);

#endif

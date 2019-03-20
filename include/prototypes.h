/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:49 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/20 15:39:49 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ssl.h"

/*
**********************************    MD5    ***********************************
**				It contains all prototypes relative to md5 hash
*/
char				*convert_md5(char *input);
char				*process_md5(t_md5 **md5);
t_md5				*initialize_md5_structure(char *input);
void				destroy_md5_structure(t_md5 *md5);
char				*prepare_padded_message(
						char *message,
						unsigned long long len,
						unsigned long long padded_len);

/*
********************************    SHA256    **********************************
**			  It contains all prototypes relative to sha256 hash
*/
char				*convert_sha256(char *input);
void				sha256_crypt(t_argument *arg);

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
void				declare_new_argument(t_ssl **ssl, char *arg, char type);
t_ssl				*declare_empty_ssl_structure(void);

/*
**	PARSER:		parse arguments and fill t_ssl structure
*/
void				parse_arguments(t_ssl **ssl, char **av);

/*
**	UTILS:		contains all functions common to any hash
*/
unsigned int		left_rotate(const unsigned int value, int shift);
void				print_memory(const char *str, size_t size);
unsigned long long	strlenu(const char *message);

#endif

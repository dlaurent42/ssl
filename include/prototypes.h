/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:49 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/23 21:04:46 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ssl.h"

/*
**********************************    MD5    ***********************************
**				It contains all prototypes relative to md5 hash
*/
char			*convert_md5(char *input);

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
void			dispatcher(t_ssl **ssl);

/*
**	DISPLAY:	handles output of the program in case of successful execution
*/
void			display(t_ssl *ssl);

/*
**	ERRORS:		handle every single fatal error in the program
*/
void			err_handler(unsigned char errcode, t_ssl *ssl);

/*
**	MEMORY:		cares about memory allocation and free of program's structures
*/
void			free_ssl(t_ssl *ssl);
void			declare_new_argument(t_ssl **ssl, char *argument, char type);
t_ssl			*declare_empty_ssl_structure(void);

/*
**	PARSER:		parse arguments and fill t_ssl structure
*/
void			parse_arguments(t_ssl **ssl, char **av);

#endif

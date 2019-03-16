/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:49 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/16 18:24:10 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ssl.h"

/*
**********************************    MD5    ***********************************
**				It contains all prototypes relative to md5 hash
*/

/*
********************************    SHA256    **********************************
**			  It contains all prototypes relative to sha256 hash
*/

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
void			declare_new_argument(t_ssl **ssl, char *argument);
void			declare_new_stdin_argument(t_ssl **ssl, char *argument);
t_ssl			*declare_empty_ssl_structure(void);

/*
**	PARSER:		parse arguments and fill t_ssl structure
*/
void			parse_arguments(t_ssl **ssl, char **av);

#endif

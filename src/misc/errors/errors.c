/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:00 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 00:25:02 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		err_handler(unsigned char errcode, t_ssl *ssl)
{
	if (errcode == ERRCODE_SSL_NO_ARG)
		ft_putendl("usage: ft_ssl command [command opts] [command args]");
	else if (errcode == ERRCODE_SSL_INVALID_CMD && ssl && ssl->hash_type)
	{
		ft_putstr_fd("ft_ssl: Error: '", 2);
		ft_putstr_fd(ssl->hash_type, 2);
		ft_putstr_fd("' is an invalid command.\n\n", 2);
		ft_putstr_fd("Standard commands:\n\n", 2);
		ft_putstr_fd("Message Digest commands:\n", 2);
		ft_putstr_fd("md5\n", 2);
		ft_putstr_fd("sha224\n", 2);
		ft_putstr_fd("sha256\n", 2);
		ft_putstr_fd("sha384\n", 2);
		ft_putstr_fd("sha512\n\n", 2);
		ft_putstr_fd("Cipher commands:\n", 2);
	}
	else if (errcode == ERRCODE_SSL_MISSING_ARG)
		ft_putendl_fd("ft_ssl: md5: option requires an argument -- s", 2);
	else
		ft_putendl_fd("An error occured.", 2);
	free_ssl(ssl);
	exit(EXIT_FAILURE);
}

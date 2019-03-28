/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:30:25 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 18:42:30 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		execute_from_stdin(t_ssl **ssl)
{
	read_from_stdin(ssl);
	if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "md5") == 0)
		(*ssl)->output = convert_md5((*ssl)->input, (*ssl)->input_size);
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha224") == 0)
		(*ssl)->output = convert_sha224((*ssl)->input, (*ssl)->input_size);
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha256") == 0)
		(*ssl)->output = convert_sha256((*ssl)->input, (*ssl)->input_size);
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha512") == 0)
		(*ssl)->output = convert_sha512((*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_stdin = TRUE;
	display(ssl, NULL);
	reset_ssl_structure(ssl);
}

void		execute_from_file(t_ssl **ssl, char *filename)
{
	read_from_file(ssl, filename);
	if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "md5") == 0)
		(*ssl)->output = convert_md5((*ssl)->input, (*ssl)->input_size);
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha224") == 0)
		(*ssl)->output = convert_sha224((*ssl)->input, (*ssl)->input_size);
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha256") == 0)
		(*ssl)->output = convert_sha256((*ssl)->input, (*ssl)->input_size);
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha512") == 0)
		(*ssl)->output = convert_sha512((*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_file = TRUE;
	display(ssl, filename);
	reset_ssl_structure(ssl);
}

void		execute_from_string(t_ssl **ssl, char *s)
{
	if (!s)
		err_handler(ERRCODE_SSL_MISSING_ARG, *ssl);
	(*ssl)->input_size = ft_strlens(s);
	if (!((*ssl)->input = ft_strdups(s)))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	if (ft_strcmps((*ssl)->hash_type, "md5") == 0)
		(*ssl)->output = convert_md5((*ssl)->input, (*ssl)->input_size);
	else if (ft_strcmps((*ssl)->hash_type, "sha224") == 0)
		(*ssl)->output = convert_sha224((*ssl)->input, (*ssl)->input_size);
	else if (ft_strcmps((*ssl)->hash_type, "sha256") == 0)
		(*ssl)->output = convert_sha256((*ssl)->input, (*ssl)->input_size);
	else if (ft_strcmps((*ssl)->hash_type, "sha512") == 0)
		(*ssl)->output = convert_sha512((*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_string = TRUE;
	display(ssl, NULL);
	reset_ssl_structure(ssl);
}

void		execute_from_nothing(t_ssl **ssl)
{
	(*ssl)->input = ft_strdups("");
	(*ssl)->input_size = 0;
	if (ft_strcmps((*ssl)->hash_type, "md5") == 0)
		(*ssl)->output = convert_md5((*ssl)->input, (*ssl)->input_size);
	else if (ft_strcmps((*ssl)->hash_type, "sha224") == 0)
		(*ssl)->output = convert_sha224((*ssl)->input, (*ssl)->input_size);
	else if (ft_strcmps((*ssl)->hash_type, "sha256") == 0)
		(*ssl)->output = convert_sha256((*ssl)->input, (*ssl)->input_size);
	else if (ft_strcmps((*ssl)->hash_type, "sha512") == 0)
		(*ssl)->output = convert_sha512((*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_stdin = TRUE;
	(*ssl)->option_p = FALSE;
	display(ssl, NULL);
	(*ssl)->option_p = TRUE;
	reset_ssl_structure(ssl);
}

void		execute_hash(t_ssl **ssl, char **av)
{
	int	i;

	i = 1;
	if (!((*ssl)->hash_type = ft_strdups(av[i])))
		err_handler(ERRCODE_SSL_NO_ARG, *ssl);
	if (!(ft_strcmps(av[i], "md5") == 0
	|| ft_strcmps(av[i], "sha224") == 0
	|| ft_strcmps(av[i], "sha256") == 0
	|| ft_strcmps(av[i], "sha512") == 0))
		err_handler(ERRCODE_SSL_INVALID_CMD, *ssl);
	if (!av[++i])
		execute_next_argument(ssl, &i, av);
	while (av[i])
	{
		execute_next_argument(ssl, &i, av);
		reset_ssl_structure(ssl);
		i += av[i] != NULL;
	}
}

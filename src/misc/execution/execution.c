/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:30:25 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 01:44:13 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		execute_from_stdin(t_ssl **ssl)
{
	read_from_stdin(ssl);
	if (!(*ssl)->error)
		(*ssl)->output = g_dispatcher[(*ssl)->hash_index].dispatch(
			(*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_stdin = TRUE;
	display(ssl, NULL);
	reset_ssl_structure(ssl);
}

void		execute_from_file(t_ssl **ssl, char *filename)
{
	read_from_file(ssl, filename);
	if (!(*ssl)->error)
		(*ssl)->output = g_dispatcher[(*ssl)->hash_index].dispatch(
			(*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_file = TRUE;
	display(ssl, filename);
	reset_ssl_structure(ssl);
}

void		execute_from_string(t_ssl **ssl, char *s)
{
	if (!s)
		err_handler(ERRCODE_SSL_MISSING_ARG, *ssl, NULL);
	(*ssl)->input_size = ft_strlens(s);
	if (!((*ssl)->input = ft_strdups(s)))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl, NULL);
	(*ssl)->output = g_dispatcher[(*ssl)->hash_index].dispatch(
			(*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_string = TRUE;
	display(ssl, NULL);
	reset_ssl_structure(ssl);
}

void		execute_from_nothing(t_ssl **ssl)
{
	(*ssl)->input = ft_strdups("");
	(*ssl)->input_size = 0;
	(*ssl)->output = g_dispatcher[(*ssl)->hash_index].dispatch(
			(*ssl)->input, (*ssl)->input_size);
	(*ssl)->from_stdin = TRUE;
	(*ssl)->option_p = FALSE;
	display(ssl, NULL);
	(*ssl)->option_p = TRUE;
	reset_ssl_structure(ssl);
}

void		execute_hash(t_ssl **ssl, char **av)
{
	int		i;
	bool	hash_ok;

	i = 1;
	hash_ok = FALSE;
	if (!av[i])
		err_handler(ERRCODE_SSL_NO_ARG, *ssl, NULL);
	while (!hash_ok && (*ssl)->hash_index < MAX_HASHES)
	{
		if (ft_strcmps(g_dispatcher[(*ssl)->hash_index].name, av[i]) == 0)
			hash_ok = TRUE;
		(*ssl)->hash_index += (hash_ok == FALSE);
	}
	if (!hash_ok)
		err_handler(ERRCODE_SSL_INVALID_CMD, *ssl, av[i]);
	if (!av[++i])
		execute_next_argument(ssl, &i, av);
	while (av[i])
	{
		execute_next_argument(ssl, &i, av);
		reset_ssl_structure(ssl);
		i += av[i] != NULL;
	}
}

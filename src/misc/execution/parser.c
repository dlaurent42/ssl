/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:30:25 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/27 19:01:11 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		execute_from_stdin(t_ssl **ssl)
{
	(void)ssl;
	display(*ssl);
	reset_ssl_structure(ssl);
}

void		execute_from_file(t_ssl **ssl, char *filename)
{
	read_from_file(ssl, filename);
	if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "md5") == 0)
		(*ssl)->output = convert_md5((*ssl)->input, strlenu((*ssl)->input));
	else if (!(*ssl)->error && ft_strcmps((*ssl)->hash_type, "sha256") == 0)
		(*ssl)->output = convert_sha256((*ssl)->input, strlenu((*ssl)->input));
	display(*ssl);
	reset_ssl_structure(ssl);
}

void		execute_from_string(t_ssl **ssl, char *s)
{
	if (!s)
		err_handler(ERRCODE_SSL_MISSING_ARG, *ssl);
	if (ft_strcmps((*ssl)->hash_type, "md5") == 0)
		(*ssl)->output = convert_md5((*ssl)->input, strlenu((*ssl)->input));
	else if (ft_strcmps((*ssl)->hash_type, "sha256") == 0)
		(*ssl)->output = convert_sha256((*ssl)->input, strlenu((*ssl)->input));
	display(*ssl);
	reset_ssl_structure(ssl);
}

void		execute_next_argument(t_ssl **ssl, int *i, char **av)
{
	bool	continue_reading;

	continue_reading = TRUE;
	while (continue_reading && av[*i])
	{
		if (ft_strcmps(av[*i], "-q") == 0)
			(*ssl)->option_q = TRUE;
		else if (ft_strcmps(av[*i], "-r") == 0)
			(*ssl)->option_r = TRUE;
		else
		{
			continue_reading = FALSE;
			(*ssl)->is_executed = TRUE;
			if (ft_strcmps(av[*i], "-p") == 0 && ((*ssl)->option_p = TRUE))
				execute_from_stdin(ssl);
			else if (ft_strcmps(av[*i], "-s") == 0)
				execute_from_string(ssl, av[++(*i)]);
			else
				execute_from_file(ssl, av[*i]);
		}
		(*i)++;	
	}
	if (continue_reading && !(*ssl)->is_executed && ((*ssl)->is_executed = TRUE))
		execute_from_stdin(ssl);
}

void		execute_hash(t_ssl **ssl, char **av)
{
	int	i;

	i = 1;
	if (!((*ssl)->hash_type = ft_strdups(av[i])))
		err_handler(ERRCODE_SSL_NO_ARG, *ssl);
	if (!(ft_strcmps(av[i], "md5") == 0 || ft_strcmps(av[i], "sha256") == 0))
		err_handler(ERRCODE_SSL_INVALID_CMD, *ssl);
	while (av[++i])
	{
		execute_next_argument(ssl, av, &i);
		reset_ssl_structure(ssl);
	}
}

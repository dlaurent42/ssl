/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:17:11 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 14:50:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	dispatch(t_ssl **ssl, int *i, bool *parse, char **av)
{
	*parse = FALSE;
	if ((*ssl)->is_executed)
		execute_from_file(ssl, av[*i]);
	else if (ft_strcmps(av[*i], "-p") == 0 && (*ssl)->option_p)
		execute_from_nothing(ssl);
	else if (ft_strcmps(av[*i], "-p") == 0 && ((*ssl)->option_p = TRUE))
	{
		(*ssl)->is_executed = FALSE;
		execute_from_stdin(ssl);
	}
	else if (ft_strcmps(av[*i], "-s") == 0)
	{
		(*ssl)->is_executed = TRUE;
		execute_from_string(ssl, av[++(*i)]);
	}
	else
	{
		(*ssl)->is_executed = TRUE;
		execute_from_file(ssl, av[*i]);
	}
}

static void	parse_and_execute(t_ssl **ssl, int *i, bool *parse, char **av)
{
	if (ft_strcmps(av[*i], "-q") == 0)
		(*ssl)->option_q = TRUE;
	else if (ft_strcmps(av[*i], "-r") == 0)
		(*ssl)->option_r = TRUE;
	else
		dispatch(ssl, i, parse, av);
}

void		execute_next_argument(t_ssl **ssl, int *i, char **av)
{
	bool	parse;

	parse = TRUE;
	while (parse && av[*i])
	{
		parse_and_execute(ssl, i, &parse, av);
		(*i) += parse;
	}
	if (parse && !(*ssl)->is_executed && ((*ssl)->is_executed = TRUE))
		execute_from_stdin(ssl);
}

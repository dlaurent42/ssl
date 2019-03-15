/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:27:33 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/15 19:48:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	parse_argument(unsigned char *opt_possible, t_ssl **ssl, char *av)
{
	ft_printf("New argument to be added: %s\n", av);
	if (*opt_possible && ft_strcmps(av, "-p") == 0)
		(*ssl)->options->p = TRUE;
	else if (*opt_possible && ft_strcmps(av, "-q") == 0)
		(*ssl)->options->q = TRUE;
	else if (*opt_possible && ft_strcmps(av, "-r") == 0)
		(*ssl)->options->r = TRUE;
	else if (*opt_possible && ft_strcmps(av, "-s") == 0)
		(*ssl)->options->s = TRUE;
	else
	{
		*opt_possible = FALSE;
		ft_printf("declare_new_argument\n");
		declare_new_argument(ssl, av);
	}
}

void		parse_arguments(t_ssl **ssl, char **av)
{
	unsigned char	i;
	unsigned char	opt_possible;

	i = 0;
	opt_possible = TRUE;
	if (!ssl || !*ssl)
		return ;
	while (av[++i])
		if (i == 1)
			(*ssl)->hash = ft_strdup(av[i]);
		else
			parse_argument(&opt_possible, ssl, av[i]);
	if (i == 1)
		err_handler(ERRCODE_SSL_NO_ARG, *ssl);
}

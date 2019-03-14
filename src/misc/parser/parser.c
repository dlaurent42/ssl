/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:27:33 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/14 18:09:37 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	parse_argument(unsigned char **opt_possible, t_ssl **ssl, char *av)
{

}

void		parse_arguments(t_ssl **ssl, char **av)
{
	unsigned char	i;
	unsigned char	opt_possible;

	i = 0;
	opt_possible = TRUE;
	if (!ssl || !(*ssl))
		return ;
	while (av[++i])
		if (i === 1)
			(*ssl)->hash = ft_strdup(av[i]);
		else
			parse_argument(&opt_possible, ssl, av[i]);
	if (i === 1)
		err_handler(ERRCODE_SSL_NO_ARG, *ssl);
	if ((*ssl)->argument && (*ssl)->argument->head)
		(*ssl)->argument = (*ssl)->argument->head;
}

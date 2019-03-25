/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:27:33 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/25 13:19:00 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	parse_files(t_ssl **ssl)
{
	t_argument	*head;

	if (!(*ssl)->argument)
		return ;
	head = (*ssl)->argument->head;
	while ((*ssl)->argument)
	{
		if ((*ssl)->argument->is_file)
			read_from_file(*ssl, (*ssl)->argument);
		if ((*ssl)->argument->is_file
		&& (*ssl)->argument->error > 0
		&& !(*ssl)->argument->file_content)
		{
			if (!((*ssl)->argument->file_content = ft_strdups("")))
				err_handler(ERRCODE_MALLOC_FAILED, *ssl);
			else
				(*ssl)->argument->content_size = 1;
		}
		(*ssl)->argument = (*ssl)->argument->next;
	}
	(*ssl)->argument = head;
}

static void	parse_argument(unsigned char *opt_possible, t_ssl **ssl, char *av)
{
	if (*opt_possible && ft_strcmps(av, "-p") == 0)
		(*ssl)->options->p = TRUE;
	else if (*opt_possible && ft_strcmps(av, "-q") == 0)
		(*ssl)->options->q = TRUE;
	else if (*opt_possible && ft_strcmps(av, "-r") == 0)
		(*ssl)->options->r = TRUE;
	else if (*opt_possible && ft_strcmps(av, "-s") == 0)
		(*ssl)->options->s = TRUE;
	else
		(*opt_possible && (*ssl)->options->s && !(*opt_possible = FALSE))
			? declare_new_argument(ssl, av, ARG_TYPE_STRING, ft_strlens(av))
			: declare_new_argument(ssl, av, ARG_TYPE_FILE, 0);
}

void		parse_arguments(t_ssl **ssl, char **av)
{
	unsigned char	i;
	unsigned char	opt_possible;

	i = 0;
	opt_possible = TRUE;
	if (!ssl || !*ssl)
		return ;
	read_from_stdin(ssl);
	while (av[++i])
		if (i == 1)
			(*ssl)->hash = ft_strdup(av[i]);
		else
			parse_argument(&opt_possible, ssl, av[i]);
	if (i == 1)
		err_handler(ERRCODE_SSL_NO_ARG, *ssl);
	parse_files(ssl);
}

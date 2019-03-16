/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:27:33 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/16 18:23:43 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static bool inputAvailable(void)  
{
	fd_set			fds;
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	return (FD_ISSET(0, &fds));
}

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
		declare_new_argument(ssl, av);
	}
}

static void	read_from_stdin(t_ssl **ssl)
{
	char	buffer[1024 + 1];
	char	*stdin;
	ssize_t	read_return;

	stdin = NULL;
	ft_bzero(buffer, 1025);
	while ((read_return = read(STDIN_FILENO, buffer, 1024)) > 0)
	{
		buffer[read_return] = '\0';
		if (!(stdin = ft_strjoinf(stdin, buffer, 1)))
			err_handler(ERRCODE_MALLOC_FAILED, *ssl);
		ft_bzero(buffer, 1025);
		ft_putendl(stdin);
	}
	declare_new_argument(ssl, stdin);
	ft_strdel(&stdin);
}

void				parse_arguments(t_ssl **ssl, char **av)
{
	unsigned char	i;
	unsigned char	opt_possible;

	i = 0;
	opt_possible = TRUE;
	if (!ssl || !*ssl)
		return ;
	if (inputAvailable())
		read_from_stdin(ssl);
	while (av[++i])
		if (i == 1)
			(*ssl)->hash = ft_strdup(av[i]);
		else
			parse_argument(&opt_possible, ssl, av[i]);
	if (i == 1)
		err_handler(ERRCODE_SSL_NO_ARG, *ssl);
}

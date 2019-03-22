/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:29:25 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/22 18:35:23 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static bool	input_available(void)
{
	fd_set			fds;
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
	return (FD_ISSET(0, &fds));
}

void		read_from_stdin(t_ssl **ssl)
{
	char	buffer[1024 + 1];
	char	*stdin;
	ssize_t	read_return;
	size_t	size;

	stdin = NULL;
	size = 0;
	ft_bzero(buffer, 1025);
	if (!input_available())
		return ;
	while ((read_return = read(STDIN_FILENO, buffer, 1024)) > 0)
	{
		buffer[read_return] = '\0';
		if (!(stdin = strnjoinsf1(stdin, buffer, size, read_return)))
			err_handler(ERRCODE_MALLOC_FAILED, *ssl);
		size += read_return;
		ft_bzero(buffer, 1025);
	}
	declare_new_argument(ssl, stdin, ARG_TYPE_STDIN, size);
	ft_strdel(&stdin);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:29:17 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/22 19:18:04 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	open_handler(t_argument **arg)
{
	int			fd;
	struct stat	buf;

	if ((fd = open((*arg)->argument, O_RDONLY)) == -1)
		(*arg)->error = errno;
	if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
		(*arg)->error = EISDIR;
	return (fd);
}

void		read_from_file(t_ssl *ssl, t_argument *arg)
{
	int			fd;
	char		buffer[1024 + 1];
	char		*file_content;
	ssize_t		read_return;

	file_content = NULL;
	ft_bzero(buffer, 1024 + 1);
	fd = open_handler(&arg);
	arg->content_size = 0;
	while (arg->error == 0 && (read_return = read(fd, buffer, 1024)) > 0)
	{
		buffer[read_return] = '\0';
		if (!(arg->file_content = strnjoinsf1(
			arg->file_content, buffer, arg->content_size, read_return)))
		{
			close(fd);
			err_handler(ERRCODE_MALLOC_FAILED, ssl);
		}
		arg->content_size += read_return;
		ft_bzero(buffer, 1024 + 1);
	}
	close(fd);
}

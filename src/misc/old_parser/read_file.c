/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:29:17 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/26 12:25:06 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char		open_handler(t_argument **arg)
{
	int			fd;
	struct stat	buf;

	if ((fd = open((*arg)->argument, O_RDONLY)) == -1)
		(*arg)->error = errno;
	if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
		(*arg)->error = EISDIR;
	return (fd);
}

static uint64_t	get_file_size(int fd)
{
	struct stat	buf;

	if (fstat(fd, &buf) != 0)
		return (0);
	return (buf.st_size);
}

static void		read_err_handler(int fd, t_ssl *ssl)
{
	close(fd);
	err_handler(ERRCODE_MALLOC_FAILED, ssl);
}

void			read_from_file(t_ssl *ssl, t_argument *arg)
{
	int			fd;
	char		*buffer;
	ssize_t		read_return;
	uint64_t	buff_size;

	fd = open_handler(&arg);
	buff_size = get_file_size(fd) / 10;
	arg->content_size = 0;
	if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buff_size + 1))))
		read_err_handler(fd, ssl);
	while (arg->error == 0 && (read_return = read(fd, buffer, buff_size)) > 0)
	{
		if (!(arg->file_content = strnjoinsf1(
		arg->file_content, buffer, arg->content_size, read_return)))
			read_err_handler(fd, ssl);
		arg->content_size += read_return;
		ft_bzero(buffer, buff_size);
	}
	close(fd);
	if (buffer)
		ft_strdel(&buffer);
}

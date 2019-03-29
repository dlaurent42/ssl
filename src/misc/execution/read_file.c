/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:29:17 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 01:27:41 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char		open_handler(t_ssl **ssl, char *filename)
{
	int			fd;
	struct stat	buf;

	if ((fd = open(filename, O_RDONLY)) == -1)
		(*ssl)->error = errno;
	if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
		(*ssl)->error = EISDIR;
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
	err_handler(ERRCODE_MALLOC_FAILED, ssl, NULL);
}

void			read_from_file(t_ssl **ssl, char *filename)
{
	int			fd;
	char		*buffer;
	ssize_t		read_return;
	uint64_t	buff_size;

	fd = open_handler(ssl, filename);
	buff_size = get_file_size(fd) / 10;
	(*ssl)->input_size = 0;
	if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buff_size + 1))))
		read_err_handler(fd, *ssl);
	while (!(*ssl)->error && (read_return = read(fd, buffer, buff_size)) > 0)
	{
		if (!((*ssl)->input = strnjoinsf1(
		(*ssl)->input, buffer, (*ssl)->input_size, read_return)))
			read_err_handler(fd, *ssl);
		(*ssl)->input_size += read_return;
		ft_bzero(buffer, buff_size);
	}
	close(fd);
	if (buffer)
		ft_strdel(&buffer);
	if (!(*ssl)->error && !(*ssl)->input)
		if (!((*ssl)->input = ft_strdups("")))
			err_handler(ERRCODE_MALLOC_FAILED, *ssl, NULL);
}

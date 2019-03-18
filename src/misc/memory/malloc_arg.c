/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:07 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 17:26:21 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	read_from_file(t_ssl *ssl, t_argument *arg)
{
	int			fd;
	char		buffer[1024 + 1];
	char		*file_content;
	ssize_t		read_return;
	struct stat	buf;

	file_content = NULL;
	ft_bzero(buffer, 1025);
	if ((fd = open(arg->argument, O_RDONLY)) == -1)
		arg->error = errno;
	if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
		arg->error = EISDIR;
	while (arg->error == 0 && (read_return = read(fd, buffer, 1024)) > 0)
	{
		buffer[read_return] = '\0';
		if (!(arg->file_content = ft_strjoinf(arg->file_content, buffer, 1)))
		{
			close(fd);
			err_handler(ERRCODE_MALLOC_FAILED, ssl);
		}
		ft_bzero(buffer, 1025);
	}
	close(fd);
}

void		declare_new_argument(t_ssl **ssl, char *argument, char type)
{
	t_argument	*new;

	new = NULL;
	if ((*ssl)->argument)
		while ((*ssl)->argument->next)
			(*ssl)->argument = (*ssl)->argument->next;
	if (!(new = (t_argument *)ft_memalloc(sizeof(t_argument))))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	new->head = ((*ssl)->argument) ? (*ssl)->argument->head : new;
	if ((*ssl)->argument)
		(*ssl)->argument->next = new;
	(*ssl)->argument = new->head;
	if (!(new->argument = ft_strdups(argument)))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	new->is_file = (type == ARG_TYPE_FILE);
	new->is_stdin = (type == ARG_TYPE_STDIN);
	new->is_string = (type == ARG_TYPE_STRING);
	(new->is_file) ? read_from_file(*ssl, new) : NULL;
	if (new->is_file && new->error > 0 && !new->file_content)
		if (!(new->file_content = ft_strdups("")))
			err_handler(ERRCODE_MALLOC_FAILED, *ssl);
}

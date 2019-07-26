/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:29:25 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 14:02:04 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		read_from_stdin(t_ssl **ssl)
{
	char	buffer[512 + 1];
	char	*stdin;
	ssize_t	read_return;

	stdin = NULL;
	(*ssl)->input_size = 0;
	ft_bzero(buffer, 512 + 1);
	while ((read_return = read(STDIN_FILENO, buffer, 512)) > 0)
	{
		if (!((*ssl)->input = strnjoinsf1(
		(*ssl)->input, buffer, (*ssl)->input_size, read_return)))
			err_handler(ERRCODE_MALLOC_FAILED, *ssl, NULL);
		(*ssl)->input_size += read_return;
		ft_bzero(buffer, 512 + 1);
	}
	if (!(*ssl)->input)
		if (!((*ssl)->input = ft_strdups("")))
			err_handler(ERRCODE_MALLOC_FAILED, *ssl, NULL);
}

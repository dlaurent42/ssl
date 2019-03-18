/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:16:26 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 15:26:03 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	hash_arguments(t_ssl *ssl, char *(*f)(char *))
{
	t_argument	*argument;

	argument = ssl->argument;
	while (argument)
	{
		if (argument->error == 0)
			argument->hashed_argument = (argument->is_file)
				? f(argument->file_content)
				: f(argument->argument);
		argument = argument->next;
	}
}

void		dispatcher(t_ssl **ssl)
{
	if (!ssl || !*ssl || !(*ssl)->hash)
		return ;
	if (ft_strcmps((*ssl)->hash, "md5") == 0)
		hash_arguments(*ssl, convert_md5);
	else if (ft_strcmps((*ssl)->hash, "sha256") == 0)
		hash_arguments(*ssl, convert_sha256);
	else
		err_handler(ERRCODE_SSL_INVALID_CMD, *ssl);
}

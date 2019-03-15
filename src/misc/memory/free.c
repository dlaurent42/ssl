/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:30:12 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/15 19:18:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void		free_arguments(t_ssl *ssl)
{
	t_argument	*tmp;

	tmp = NULL;
	if (!ssl->argument)
		return ;
	ssl->argument = ssl->argument->head;
	while (ssl->argument)
	{
		tmp = ssl->argument->next;
		ft_strdel(&ssl->argument->hashed_argument);
		ft_strdel(&ssl->argument->argument);
		free(ssl->argument);
		ssl->argument = tmp;
	}
	ssl->argument = NULL;
}

void			free_ssl(t_ssl *ssl)
{
	if (!ssl)
		return ;
	ft_strdel(&ssl->hash);
	if (ssl->options)
		free(ssl->options);
	free_arguments(ssl);
}

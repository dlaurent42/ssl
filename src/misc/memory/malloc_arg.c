/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:07 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/16 18:24:37 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	declare_new_stdin_argument(t_ssl **ssl, char *argument)
{
	t_argument	*new;

	new = NULL;
	if ((*ssl)->argument)
		while ((*ssl)->argument->next)
			(*ssl)->argument = (*ssl)->argument->next;
	if (!(new = (t_argument *)ft_memalloc(sizeof(t_argument))))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	new->is_stdin = TRUE;
	new->head = ((*ssl)->argument) ? (*ssl)->argument->head : new;
	if ((*ssl)->argument)
		(*ssl)->argument->next = new;
	(*ssl)->argument = new->head;
	if (!(new->argument = ft_strdups(argument)))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
}

void	declare_new_argument(t_ssl **ssl, char *argument)
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
}

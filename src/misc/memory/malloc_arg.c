/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:07 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/22 18:27:35 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		declare_new_argument(t_ssl **ssl, char *arg, char type, size_t size)
{
	t_argument	*new;

	new = NULL;
	if ((*ssl)->argument)
		while ((*ssl)->argument->next)
			(*ssl)->argument = (*ssl)->argument->next;
	if (!(new = (t_argument *)ft_memalloc(sizeof(t_argument))))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	new->head = ((*ssl)->argument) ? (*ssl)->argument->head : new;
	new->content_size = size;
	if ((*ssl)->argument)
		(*ssl)->argument->next = new;
	(*ssl)->argument = new->head;
	new->argument = (type == ARG_TYPE_STDIN && !arg)
		? ft_strdups("")
		: ft_strdups(arg);
	if (!new->argument)
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	new->is_file = (type == ARG_TYPE_FILE);
	new->is_stdin = (type == ARG_TYPE_STDIN);
	new->is_string = (type == ARG_TYPE_STRING);
}

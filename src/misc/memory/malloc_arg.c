/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:07 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 14:32:29 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	debug_new_argument(char *argument, char type)
{
	size_t	len;

	len = ft_strlens(argument);
	(argument[len - 1] == '\n')
		? ft_printf(
			"\nDeclaring new argument:\nContent:\t%sType   :\t%d\n",
			argument,
			type)
		: ft_printf(
			"\nDeclaring new argument:\nContent:\t%s\nType   :\t%d\n",
			argument,
			type);
}

void	declare_new_argument(t_ssl **ssl, char *argument, char type)
{
	t_argument	*new;

	new = NULL;
	debug_new_argument(argument, type);
	if ((*ssl)->argument)
		while ((*ssl)->argument->next)
			(*ssl)->argument = (*ssl)->argument->next;
	if (!(new = (t_argument *)ft_memalloc(sizeof(t_argument))))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
	new->head = ((*ssl)->argument) ? (*ssl)->argument->head : new;
	new->is_file = (type == ARG_TYPE_FILE);
	new->is_stdin = (type == ARG_TYPE_STDIN);
	new->is_string = (type == ARG_TYPE_STRING);
	if ((*ssl)->argument)
		(*ssl)->argument->next = new;
	(*ssl)->argument = new->head;
	if (!(new->argument = ft_strdups(argument)))
		err_handler(ERRCODE_MALLOC_FAILED, *ssl);
}

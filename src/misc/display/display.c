/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:30:48 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 15:35:32 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	display(t_ssl *ssl)
{
	int			num;
	t_argument	*arg;

	num = 0;
	if (!ssl)
		return ;
	arg = ssl->argument;
	while (arg)
	{
		ft_printf("Argument number %d:\n", num);
		if (arg->is_file)
			ft_printf("\tType: File\n");
		if (arg->is_stdin)
			ft_printf("\tType: STDIN\n");
		if (arg->is_string)
			ft_printf("\tType: string\n");
		(arg->argument[ft_strlens(arg->argument) - 1] == '\n')
			? ft_printf("\tArg : %s", arg->argument)
			: ft_printf("\tArg : %s\n", arg->argument);
		(arg->is_file && arg->error)
			? ft_printf("\tFile error: %d\n", arg->error)
			: ft_printf("\tFile content: %s", arg->file_content);
		ft_printf("\tHash: %s\n\n", arg->hashed_argument);
		num++;
		arg = arg->next;
	}
}

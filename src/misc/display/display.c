/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:30:48 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 17:28:21 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/*
** static void	debug_argument(t_argument *arg)
** {
** 	if (arg->is_file)
** 		ft_printf("\tType: File\n");
** 	if (arg->is_stdin)
** 		ft_printf("\tType: STDIN\n");
** 	if (arg->is_string)
** 		ft_printf("\tType: string\n");
** 	(arg->argument[ft_strlens(arg->argument) - 1] == '\n')
** 		? ft_printf("\tArg : %s", arg->argument)
** 		: ft_printf("\tArg : %s\n", arg->argument);
** 	(arg->is_file && arg->error)
** 		? ft_printf("\tFile error: %d\n", arg->error)
** 		: ft_printf("\tFile content: %s", arg->file_content);
** 	ft_printf("\tHash: %s\n\n", arg->hashed_argument);
** }
*/

static char	*get_hash(char *hash)
{
	if (ft_strcmps(hash, "md5") == 0)
		return ("MD5");
	if (ft_strcmps(hash, "sha256") == 0)
		return ("SHA256");
	return ("UNKNOWN");
}

static void	print_error_argument(t_ssl *ssl, t_argument *arg)
{
	if (arg->error == EACCES)
		ft_printf("ft_ssl: %s: %s: Permission denied.\n",
			ssl->hash, arg->argument);
	else if (arg->error == ENOENT)
		ft_printf("ft_ssl: %s: %s: No such file or directory.\n",
		ssl->hash, arg->argument);
	else if (arg->error == EISDIR)
		ft_printf("ft_ssl: %s: %s: Is a directory.\n",
		ssl->hash, arg->argument);
	else
		ft_printf("ERRCODE: %d\n", arg->error);
}

static void	print_stdin_argument(t_options *options, t_argument *argument)
{
	if (options->p)
		(argument->argument[ft_strlens(argument->argument) - 1] == '\n')
			? ft_putstr(argument->argument)
			: ft_putendl(argument->argument);
	ft_putendl(argument->hashed_argument);
}

static void	print_other_valid_argument(t_ssl *ssl, t_argument *arg)
{
	if (ssl->options->q)
		ft_putendl(arg->hashed_argument);
	else if (ssl->options->r)
		(arg->is_file)
			? ft_printf("%s %s\n", arg->hashed_argument, arg->argument)
			: ft_printf("%s \"%s\"\n", arg->hashed_argument, arg->argument);
	else
		(arg->is_file)
			? ft_printf("%s (%s) = %s\n",
				get_hash(ssl->hash), arg->argument, arg->hashed_argument)
			: ft_printf("%s (\"%s\") = %s\n",
				get_hash(ssl->hash), arg->argument, arg->hashed_argument);
}

void		display(t_ssl *ssl)
{
	t_argument	*argument;

	if (!ssl)
		return ;
	argument = ssl->argument;
	while (argument)
	{
		if (argument->is_stdin)
			print_stdin_argument(ssl->options, argument);
		else if (argument->is_file && argument->error)
			print_error_argument(ssl, argument);
		else
			print_other_valid_argument(ssl, argument);
		argument = argument->next;
	}
}

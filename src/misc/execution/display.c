/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:30:48 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/28 18:41:36 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*get_hash(char *hash)
{
	if (ft_strcmps(hash, "md5") == 0)
		return ("MD5");
	if (ft_strcmps(hash, "sha224") == 0)
		return ("SHA224");
	if (ft_strcmps(hash, "sha256") == 0)
		return ("SHA256");
	if (ft_strcmps(hash, "sha512") == 0)
		return ("SHA512");
	return ("UNKNOWN");
}

static void	print_error_argument(int error, char *hash_type, char *filename)
{
	if (error == EACCES || error == ENOENT || error == EISDIR)
	{
		ft_printf("ft_ssl: %s: ", hash_type);
		write(1, filename, ft_strlens(filename));
	}
	if (error == EACCES)
		ft_putendl(": Permission denied.");
	else if (error == ENOENT)
		ft_putendl(": No such file or directory.");
	else if (error == EISDIR)
		ft_putendl(": Is a directory.");
	else
		ft_printf("ERRCODE: %d\n", error);
}

static void	print_stdin_argument(t_ssl **ssl)
{
	if ((*ssl)->option_p)
		write(1, (*ssl)->input, (*ssl)->input_size);
	if ((*ssl)->option_p && (*ssl)->input[(*ssl)->input_size - 1] != '\n')
		write(1, "\n", 1);
	ft_putendl((*ssl)->output);
}

static void	print_other_valid_argument(t_ssl **ssl, char *filename)
{
	if ((*ssl)->option_r && (*ssl)->from_file)
	{
		ft_printf("%s ", (*ssl)->output);
		write(1, filename, ft_strlens(filename));
		ft_putendl("");
	}
	else if ((*ssl)->option_r)
	{
		ft_printf("%s \"", (*ssl)->output);
		write(1, (*ssl)->input, (*ssl)->input_size);
		ft_putendl("\"");
	}
	else if ((*ssl)->from_file)
	{
		ft_printf("%s (", get_hash((*ssl)->hash_type));
		write(1, filename, ft_strlens(filename));
		ft_printf(") = %s\n", (*ssl)->output);
	}
	else
	{
		ft_printf("%s (\"", get_hash((*ssl)->hash_type));
		write(1, (*ssl)->input, (*ssl)->input_size);
		ft_printf("\") = %s\n", (*ssl)->output);
	}
}

void		display(t_ssl **ssl, char *filename)
{
	if ((*ssl)->from_stdin)
		print_stdin_argument(ssl);
	else if ((*ssl)->from_file && (*ssl)->error)
		print_error_argument((*ssl)->error, (*ssl)->hash_type, filename);
	else if ((*ssl)->option_q)
		ft_putendl((*ssl)->output);
	else
		print_other_valid_argument(ssl, filename);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:32 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 15:33:19 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

// static void		convert_sha256_tmp(t_ssl *ssl)
// {
// 	t_argument		*cpy;

// 	ft_printf("Received some bs for: %s\n", ssl->hash);
// 	cpy = ssl->argument;
// 	while (cpy)
// 	{
// 		ft_printf("We will convert: %s\n", cpy->argument);
// 		sha256_crypt(cpy);
// 		ft_printf("We have it converted: %s\n", cpy->hashed_argument);
// 		cpy = cpy->next;
// 	}
// }

char		*convert_sha256(char *input)
{
	char	*output;

	(void)input;
	if (!(output = ft_strdups("sha256 hashed string")))
		return (NULL);
	return (output);
}

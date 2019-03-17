/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:32 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/17 20:21:36 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		convert_sha256(t_ssl *ssl)
{
	t_argument		*cpy;

	ft_printf("Received some bs for: %s\n", ssl->hash);
	cpy = ssl->argument;
	while (cpy)
	{
		ft_printf("We will convert: %s\n", cpy->argument);
		sha256_crypt(cpy);
		ft_printf("We have it converted: %s\n", cpy->hashed_argument);
		cpy = cpy->next;
	}
}

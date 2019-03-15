/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:29 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/15 19:56:45 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		main(int ac, char **av)
{
	t_ssl	*ssl;

	int i = -1;
	while (++i < ac)
		ft_printf("arg[%d]: %s\n", i, av[i]);
	ssl = declare_empty_ssl_structure();
	parse_arguments(&ssl, av);
	dispatcher(&ssl);
	display(ssl);
	free_ssl(ssl);
	return (0);
}

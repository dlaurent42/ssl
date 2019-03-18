/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:29 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 15:11:36 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		main(int ac, char **av)
{
	t_ssl	*ssl;

	(void)ac;
	ssl = declare_empty_ssl_structure();
	parse_arguments(&ssl, av);
	dispatcher(&ssl);
	display(ssl);
	free_ssl(ssl);
	return (0);
}

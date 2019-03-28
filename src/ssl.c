/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:29 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/27 11:32:49 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		main(int ac, char **av)
{
	int		status;
	t_ssl	*ssl;

	(void)ac;
	ssl = declare_empty_ssl_structure();
	execute_hash(&ssl, av);
	status = ssl->is_error;
	free_ssl(ssl);
	return (status);
}

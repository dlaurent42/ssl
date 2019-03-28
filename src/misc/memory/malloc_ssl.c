/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_ssl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:07:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/27 17:06:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	reset_ssl_structure(t_ssl **ssl)
{
	if ((*ssl)->input)
		ft_strdel(&(*ssl)->input);
	if ((*ssl)->output)
		ft_strdel(&(*ssl)->output);
	(*ssl)->option_p = FALSE;
	(*ssl)->option_q = FALSE;
	(*ssl)->option_r = FALSE;
}

t_ssl	*declare_empty_ssl_structure(void)
{
	t_ssl	*ssl;

	ssl = NULL;
	if (!(ssl = (t_ssl *)ft_memalloc(sizeof(t_ssl))))
		err_handler(ERRCODE_MALLOC_FAILED, NULL);
	return (ssl);
}

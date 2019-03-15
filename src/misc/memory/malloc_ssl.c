/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_ssl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:07:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/15 19:20:47 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_ssl	*declare_empty_ssl_structure(void)
{
	t_ssl	*ssl;

	ssl = NULL;
	if (!(ssl = (t_ssl *)ft_memalloc(sizeof(t_ssl))))
		err_handler(ERRCODE_MALLOC_FAILED, NULL);
	if (!(ssl->options = (t_options *)ft_memalloc(sizeof(t_options))))
		err_handler(ERRCODE_MALLOC_FAILED, ssl);
	return (ssl);
}

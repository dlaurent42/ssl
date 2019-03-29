/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:07:38 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 01:41:59 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_ssl	*declare_empty_ssl_structure(void)
{
	t_ssl	*ssl;

	ssl = NULL;
	if (!(ssl = (t_ssl *)ft_memalloc(sizeof(t_ssl))))
		err_handler(ERRCODE_MALLOC_FAILED, NULL, NULL);
	return (ssl);
}

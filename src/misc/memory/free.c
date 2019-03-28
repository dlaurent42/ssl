/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:30:12 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/27 17:06:22 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void			free_ssl(t_ssl *ssl)
{
	if (!ssl)
		return ;
	if (ssl->hash_type)
		ft_strdel(&ssl->hash_type);
	if (ssl->input)
		ft_strdel(&ssl->input);
	if (ssl->output)
		ft_strdel(&ssl->output);
	free_arguments(ssl);
	free(ssl);
}

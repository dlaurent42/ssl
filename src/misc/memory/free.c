/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:30:12 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/29 01:25:02 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void			free_ssl(t_ssl *ssl)
{
	if (!ssl)
		return ;
	if (ssl->input)
		ft_strdel(&ssl->input);
	if (ssl->output)
		ft_strdel(&ssl->output);
	free(ssl);
}

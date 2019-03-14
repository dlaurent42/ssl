/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:16:26 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/14 17:19:47 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	dispatcher(t_ssl **ssl)
{
	if (!ssl || !(*ssl) || !(*ssl)->hash)
		return ;
	if (ft_strcmps((*ssl)->hash, "md5"))
		md5(ssl);
	else if (ft_strcmps((*ssl)->hash, "sha256"))
		sha256(ssl);
	else
		err_handler(ERRCODE_SSL_INVALID_CMD, *ssl);
}

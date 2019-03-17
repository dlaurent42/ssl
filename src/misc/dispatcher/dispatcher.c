/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:16:26 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/17 20:15:21 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	dispatcher(t_ssl **ssl)
{
	if (!ssl || !*ssl || !(*ssl)->hash)
		return ;
	if (ft_strcmps((*ssl)->hash, "md5") == 0)
		ft_printf("Should run md5(ssl)\n");
	else if (ft_strcmps((*ssl)->hash, "sha256") == 0)
		convert_sha256(*ssl);
	else
		err_handler(ERRCODE_SSL_INVALID_CMD, *ssl);
}

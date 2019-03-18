/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:37 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 15:18:59 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char		*convert_md5(char *input)
{
	char	*output;

	(void)input;
	if (!(output = ft_strdups("MD5 hashed string")))
		return (NULL);
	return (output);
}

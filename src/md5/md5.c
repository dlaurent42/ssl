/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:04:37 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/21 18:36:53 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char		*convert_md5(char *input)
{
	t_md5	*md5;

	if (!(md5 = initialize_md5_structure(input)))
		return (NULL);
	ft_printf("%s\n", process_md5(&md5));
	destroy_md5_structure(md5);
	return (NULL);
}

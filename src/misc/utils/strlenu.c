/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlenu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:38:15 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/20 13:38:40 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	strlenu(const char *message)
{
	int					i;
	unsigned long long	len;

	i = 0;
	len = 0;
	if (!message)
		return (len);
	while (message[i])
	{
		if ((unsigned char)message[i] < 0b10000000
		|| (unsigned char)message[i] >= 0b11000000)
			len++;
		i++;
	}
	return (len);
}

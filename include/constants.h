/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:48 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/18 17:29:33 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include "ssl.h"

/*
** errcodes
*/
# define ERRCODE_MALLOC_FAILED		-1
# define ERRCODE_SSL_NO_ARG			1
# define ERRCODE_SSL_INVALID_CMD	2

/*
** argument's types
*/
# define ARG_TYPE_STDIN				0
# define ARG_TYPE_FILE				1
# define ARG_TYPE_STRING			2

#endif

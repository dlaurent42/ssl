/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:01:50 by dlaurent          #+#    #+#             */
/*   Updated: 2019/03/14 17:02:22 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct			s_argument
{
	char				*hashed_argument;
	char				*argument;
	unsigned char		is_file	:1;
	unsigned char		empty	:7;
	struct s_argument	*head;
	struct s_argument	*next;
}						t_argument;

/*
**	OPTIONS
**		• -p, echo STDIN to STDOUT and append the checksum to STDOUT
**		• -q, quiet mode
**		• -r, reverse the format of the output
**		• -s, print the sum of the given string
*/
typedef struct			s_options
{
	unsigned char		p		:1;
	unsigned char		q		:1;
	unsigned char		r		:1;
	unsigned char		s		:1;
	unsigned char		empty	:4;
}						t_options;

typedef struct			s_ssl
{
	char				*hash;
	t_options			options;
	t_argument			*argument;
}						t_ssl;

#endif

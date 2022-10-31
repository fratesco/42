/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:57:22 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/30 12:57:29 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

void	print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	print_nn(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_num(char *num, t_dict dict, int *print_delim)
{
	char	*value;

	if (*print_delim)
		print_nn(" ");
	else
		*print_delim = 1;
	value = dict_get_value(&dict, num);
	if (value != NONE_VALUE)
		print_nn(value);
}

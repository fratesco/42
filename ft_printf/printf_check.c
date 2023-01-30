/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/30 17:35:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_special(const char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			return (FOUND);
		i++;
	}
	if (str[i] == '%')
		return (ERROR);
	return (NOTHING);
}

int	parsing_checking(const char *str, va_list list)
{
	
}
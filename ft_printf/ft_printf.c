/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:24:50 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/30 17:00:18 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_special(const char *str)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (((++counter) % 2) == 0)
				write(1, '%', 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		status;
	va_list	vars;

	status = check_special(str);
	if (status == NOTHING)
		ft_putstr_special(str);
	else if (status == FOUND)
	{
		
	}
	status = 0;
	if (status == ERROR)
		return (1);
	return (0);
}
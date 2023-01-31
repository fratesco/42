/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:24:50 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/31 16:44:00 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(unsigned int nbr, size_t *n)
{
	if (nbr == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, 1);
		ft_putnbr_fd(nbr % 10, 1);
	}
	else
	{
		ft_putchar_fd((48 + nbr), 1);
		*n += 1;
	}
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_special(const char *str, size_t *n)
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
			{
				write(1, '%', 1);
				*n += 1;
			}
		}
		else
		{
			write(1, &str[i], 1);
			*n += 1;
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		status;
	va_list	vars;
	size_t	n_char;

	n_char = 0;
	status = check_special(str);
	if (status == NOTHING)
		ft_putstr_special(str, *n_char);
	else if (status == FOUND)
	{
		va_start(vars);
		status = parsing_checking(str, vars, *n_char);
	}
	status = 0;
	if (status == ERROR)
		return (n_char);
	return (n_char);
}
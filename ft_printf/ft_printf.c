/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:24:50 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/01 16:35:45 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, size_t *n)
{
	write(1, &c, 1);
	(*n)++;
}

void	ft_putnbr(long nbr, size_t *n)
{
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nbr = 147483648;
		*n += 2;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		*n += 1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, n);
		ft_putnbr(nbr % 10, n);
	}
	else
	{
		nbr += 48;
		write(1, &(nbr), 1);
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
	if (!str)
		ft_putstr_special("(null)", n);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			if (((++counter) % 2) == 0)
			{
				write(1, "%", 1);
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
		ft_putstr_special(str, &n_char);
	else if (status == FOUND)
	{
		va_start(vars, str);
		status = parsing_checking(str, vars, &n_char);
	}
	if (status == ERROR)
		return (n_char);
	va_end(vars);
	return (n_char);
}

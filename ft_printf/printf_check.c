/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/01 15:51:55 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	conversion(const char c, va_list list, size_t *n)
{
	char	b;

	if (c == 'c')
	{
		b = va_arg(list, int);
		write(1, &b, 1);
		*n += 1;
	}
	else if (c == 's')
		ft_putstr_special(va_arg(list, char *), n);
	else if (c == 'p')
		ft_putnbr_hex(va_arg(list, unsigned long), 0, n);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int), n);
	else if (c == 'u')
		ft_putnbr(va_arg(list, unsigned int), n);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(list, int), 0, n);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(list, int), 1, n);
}

int	parsing_checking(const char *str, va_list list, size_t *n)
{
	int		i;
	t_bool	check;

	i = 0;
	check = FALSE;
	while (str[i])
	{
		if (str[i] == '%' && !check)
			check = TRUE;
		else if (check && str[i] == '%')
		{
			ft_putchar(str[i++], n);
			check = FALSE;
		}
		else if (check)
		{
			conversion(str[i], list, n);
			check = FALSE;
		}
		else
			ft_putchar(str[i], n);	
		i++;
	}
	return (NOTHING);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/31 16:26:11 by fgolino          ###   ########.fr       */
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

void	conversion(const char c, va_list list)
{
	if (c == 'c')
		ft_putchar(va_arg(list, char));
	else if (c == 's')
		ft_putstr_special(va_arg(list, char *));
	else if (c == 'p')
		ft_putnbr_base(va_arg(list, unsigned long), 16);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		ft_putnbr()
}

int	parsing_checking(const char *str, va_list list)
{
	char	*random;
	int		i;
	t_bool	check;

	i = 0;
	check = FALSE;
	random = va_arg(list, char *);
	while (str[i])
	{
		if (str[i] == '%' && !check)
			check = TRUE;
		else if (check && str[i] == '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		else if (check)
		{
			conversion(str[i], list);
			check = FALSE;
		}
		i++;
	}
}

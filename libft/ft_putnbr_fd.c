/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:18:47 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/23 16:27:01 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	potenza(int e, int b)
{
	int	base;

	base = b;
	while (e - 1 > 1)
	{
		b = b * base;
		e--;
	}
	return (b);
}

int	cifre(int nb)
{
	int	c;

	c = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

void	positivo(int nb, int fd)
{
	int		a;
	char	scritta;
	char	ultima_cifra;

	a = cifre(nb);
	while (a > 1)
	{
		scritta = nb / potenza(a, 10) + '0';
		write(1, &scritta, 1);
		ultima_cifra = nb / potenza(a, 10);
		nb = nb - (ultima_cifra * potenza(a, 10));
		a--;
	}
	scritta = nb + '0';
	write(fd, &scritta, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{		
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	positivo(nb, fd);
}
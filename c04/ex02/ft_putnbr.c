/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:24:31 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/26 09:11:15 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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

void	positivo(int nb)
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
	write(1, &scritta, 1);
}

void	ft_putnbr(int nb)
{
	long num;

	num = nb;
	if (num < 0)
	{		
		num = num * (-1);
		write(1, "-", 1);
	}
	positivo(num);
}

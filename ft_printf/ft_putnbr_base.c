/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:00:31 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/31 16:37:11 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base(int nbr, char *base, int *n)
{
	int		nb;
	int		i;
	long	lnbr;
	char	num[32];

	if (check0(nbr, base, n) == 1)
		return ;
	nb = check(base);
	if (nb == 1)
		return ;
	lnbr = nbr;
	if (lnbr < 0)
	{
		write(1, "-", 1);
		lnbr *= -1;
		*n += 1;
	}
	i = 0;
	while (lnbr > 0)
	{
		num[i] = lnbr % nb;
		lnbr /= nb;
		i++;
	}
	print(num, i, base, n);
}

int	check0(int nbr, char *b, int *n)
{
	if (nbr == 0)
	{
		write(1, &b[0], 1);
		*n += 1;
		return (1);
	}
	return (0);
}

void	print(char *num, int i, char *base, int *n)
{
	int	x;

	i--;
	while (i >= 0)
	{
		x = num[i];
		write(1, &base[x], 1);
		*n += 1;
		i--;
	}
}

int	check(char *base)
{
	int	nb;
	int	i;

	nb = 0;
	while (base[nb])
	{
		if (base[nb] == '+' || base[nb] == '-')
			return (1);
		if (base[nb] > 126 || base[nb] < 32)
			return (1);
		i = nb + 1;
		while (base[i])
		{
			if (base[i] == base[nb])
				return (1);
			i++;
		}
		nb++;
	}
	if (nb <= 1)
		return (1);
	return (nb);
}

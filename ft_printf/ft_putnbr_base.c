/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:00:31 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/01 14:49:29 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(int nbr, int caser, size_t *n)
{
	int		nb;
	int		i;
	long	lnbr;
	char	num[32];

	if (check0(nbr, n) == 1)
		return ;
	nb = 16;
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
	print(num, i, caser, n);
}

int	check0(int nbr, size_t *n)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		*n += 1;
		return (1);
	}
	return (0);
}

void	print(char *num, int i, int caser, size_t *n)
{
	int		x;
	char	*base;

	if (caser == 0)
		base = "0123456789abcdef\0";
	else if (caser == 1)
		base = "0123456789ABCDEF\0";
	i--;
	while (i >= 0)
	{
		x = num[i];
		write(1, &base[x], 1);
		*n += 1;
		i--;
	}
}

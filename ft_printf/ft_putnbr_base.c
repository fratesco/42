/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:00:31 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/31 16:45:15 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base(int nbr, int base, size_t *n)
{
	int		nb;
	int		i;
	long	lnbr;
	char	num[32];

	if (check0(nbr, base, n) == 1)
		return ;
	nb = base;
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

int	check0(int nbr, char *b, size_t *n)
{
	if (nbr == 0)
	{
		write(1, &b[0], 1);
		*n += 1;
		return (1);
	}
	return (0);
}

void	print(char *num, int i, char *base, size_t *n)
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

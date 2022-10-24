/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:07:01 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 04:20:35 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	loop(char *str, int i, char *base)
{
	int	nb;

	nb = 0;
	while (str[i] < 58 && str[i] > 47 && str[i] != 0)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb, base);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	while (str[i] != 0)
	{
		if (str[i] == ' ' || str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			sign = sign * (-1);
			i++;
		}
		else if (str[i] < 58 && str[i] > 47)
		{
			nb = loop(str, i, base);
			return (nb * sign);
		}
	}
	return (0);
}
int		check(char *base);
void	print(char *num, int i, char *base);
int		check0(int nbr);

int	ft_putnbr_base(int nbr, char *base)
{
	int		nb;
	int		i;
	long	lnbr;
	char	num[31];

	if (check0(nbr) == 1)
		return ;
	nb = check(base);
	if (nb == 1)
		return ;
	lnbr = nbr;
	if (lnbr < 0)
	{
		lnbr *= -1;
	}
	i = 0;
	while (lnbr > 0)
	{
		num[i] = lnbr % nb;
		lnbr /= nb;
		i++;
	}
	return;
}

int	check0(int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int	check(char *base)
{
	int		nb;
	int		i;

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

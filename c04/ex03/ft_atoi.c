/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:07:01 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/30 11:10:38 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	loop(char *str, int i)
{
	long	nb;

	nb = 0;
	while (str[i] < 58 && str[i] > 47 && str[i] != 0)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return ((int)nb);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	long	nb;

	i = 0;
	sign = 1;
	while (str[i] != 0)
	{
		if ((str[i] < 14 && str[i] > 8) || str[i] == '+' || str[i] == ' ')
			i++;
		else if (str[i] == '-')
		{
			sign = sign * (-1);
			i++;
		}
		else if (str[i] < 58 && str[i] > 47)
		{
			nb = loop(str, i);
			return (int(nb * sign));
		}
		else
			i++;
	}
	return (0);
}

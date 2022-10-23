/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:07:01 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 01:47:38 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	loop(char *str, int i)
{
	int	nb;

	nb = 0;
	while (str[i] < 58 && str[i] > 47 && str[i] != 0)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	ft_atoi(char *str)
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
			nb = loop(str, i);
			return (nb * sign);
		}
	}
	return (0);
}

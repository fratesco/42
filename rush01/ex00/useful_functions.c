/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:57:31 by rilliano          #+#    #+#             */
/*   Updated: 2022/10/22 18:32:34 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	conto;

	conto = 0;
	while (str[conto] != 0)
		conto++;
	return (conto);
}

int	base_n(char *str)
{
	int	n;

	n = 1;
	while (n < 9)
	{
		if ((((strlen(str) + 1) / 2) / (n*n) ) == n)
			return (n);
		else
			n++;
		if (n > 9)
			write(1, "Error\n", 6);
	}
}

int	input_check(int	a, char *str, int n)
{
	int	i;

	i = 1;
	if (a != 1 || ft_strlen(str) != (n*n) + 1)
		return (0);
	while (i < (n * n * 2 - 1)
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] > '0' && str[i] <= ('0' + n))
			i++;
		else
			return (0);
	}
	return (1);
}
	

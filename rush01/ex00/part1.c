/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:57:31 by rilliano          #+#    #+#             */
/*   Updated: 2022/10/23 17:25:59 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	check(int	a)
{
	if (a != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
int	ft_strlen(char *str)
{
	int	conto;

	conto = 0;
	while (str[conto] != 0)
		conto++;
	conto++;
	return (conto);
}

int	base_n(char *str) //Credits to Francesco Emanuele Borroto Colon, da un'idea di Antonio Ricci.
{
	int n;

	n = 1;
	while (1)
	{	
		if ((((ft_strlen(str)) / 2) / n) == n)
			return (n);
		else
			n++;
		if (n > 9)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
}

int	input_check(char *str, int n)
{
	int	i;

	i = 1;
	if (ft_strlen(str) != (n*n) + 1)
		return (0);
	while (i < (n * n * 2))
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

int	**matrix_generator(int	n)
{
	int	**matrix;
	int	i;

	i = 0;
	matrix = (int **)malloc(n * sizeof(int*));
	while (i < n)
	{
		matrix[i] = (int *)malloc(n * sizeof(int));
		i++;
	}
	return (matrix);
}
void	print_matrix(int	n, int **matrix)
{
	int c;
	int c1;
	char a;

	c1 = 0;
	while (c1 <= n )
	{
		c = 0;
		while (c <= n)
		{
			a = matrix[n][c] + '0';
			write (1, &a, 1);
			c++;
		}
		c1++;
	}
}

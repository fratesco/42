/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:56:21 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/23 18:46:05 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	input_interpreter(int	n, int	**input, int	row);
int	**matrix_fill(int	n, int	**matrix, int	**input)
{
	int	row;
	int	col;
	int how;

	row = 0;
	col = 0;
	while (row < n)
	{
		how = input_interpreter(n, input, row);
		if (how == 0)
			break ;
		col = 0;
		while (col < how)
		{
			matrix[row][col] = n - (how -1);
			col++;
		}
		row++;
	}
	return (matrix);
}

int	input_interpreter(int	n, int	**input, int	row)
{
	int	i;

	i = 0;
	if (input[2][row] == n)
	{
		if (input[3][row] != 1)
   			return (0);
		else
			return (n);
	}
	return (input[2][row]);
}

		


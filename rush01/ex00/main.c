/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:50:39 by rilliano          #+#    #+#             */
/*   Updated: 2022/10/23 18:44:15 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_n(char *str);
int	input_check(char	*str, int	n);
int	**matrix_generator(int	n);
void	print_matrix(int	n, int	**matrix);
int	**matrix_fill(int	n, int	**matrix, int	**input);
int	**input_sorter(char	*str, int	n);
int	input_interpreter(int	n, int	**input, int	row);
int	check(int	a);

int	main (int argc, char** argv)
{
	int	i;
	int n;
	int	**matrix;
	int	**input;
	if (check(argc) == 0)
		return (0);
	n = base_n(argv[1]);
	if (input_check(argv[1], n))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	matrix = matrix_generator(n);
	input = input_sorter(argv[1], n);
	i = 0;
	while (i < 4)
	{

		if (input_interpreter(n, input, i) == 0)
		{
			write(1, "No solution found", 17);
			return (0);
		}
		i++;
	}
	matrix = (matrix_fill(n , matrix, input));
	
	
	//print_matrix(n, matrix); 
}

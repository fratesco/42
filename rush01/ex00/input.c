/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:57:50 by rilliano          #+#    #+#             */
/*   Updated: 2022/10/23 18:37:00 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
int	ft_strlen(char *str);

int	*input4(int	n, char *str, int	offset)
{
	int	i;
	int j;
	int *arr_in;

	i = offset;
	j = 0;
	arr_in = (int *)malloc(n * sizeof(int));
	while (i < (n*2) + offset - 1)
	{

		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		else
		{
			arr_in[j] = str[i] - '0';
			j++;
			i++;
		}
	}
	write(1, " ", 1);
	return(arr_in);
}

int	**input_sorter(char	*str, int	n)
{
	int **input;
	int	i;

	i = 0;
	input = (int **)malloc(4 * sizeof(int *));
	while (i < 4)
	{
		input[i] = (int *)malloc(n * sizeof(int));
		i++;
	}
	input[0] = input4(n, str, 0);
	input[1] = input4(n, str, 8);
	input[2] = input4(n, str, 16);
	input[3] = input4(n, str, 24);
	return (input);
}

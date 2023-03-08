/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:47:50 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/09 00:10:32 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_inserter(char	**params, long **stack, int i)
{
	while (i > 0)
	{
		stack[0][i] = ft_atoi(params[i]);
		i--;
	}
}

int	check_parameters(char **params, int num)
{
	int	i;

	while (num > 0)
	{
		i = 0;
		while (params[num - 1][i])
		{
			if (params[num - 1][i] < 48 || params[num - 1][i] > 57)
			{
				ft_printf("Error\n");
				return (-1);
			}
			i++;
		}
		num -= 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;

	if (argc < 2)
		return (0);
	if (check_parameters(argv, argc) != 0)
		return (0);
	stack_a = (long *)malloc(sizeof(long) * (argc - 1));
	stack_inserter(argv, &stack_a, argc);
}
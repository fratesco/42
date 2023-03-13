/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:47:50 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/13 17:39:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_parameters(char **params, int num)
{
	int	i;

	while (num > 1)
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

t_stack	*stack_generator(int len, char **argv)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	stack = new(ft_atoi(argv[i++]));
	tmp = stack;
	while (i < len)
	{
		tmp->next = new(ft_atoi(argv[i++]));
		if (tmp->next->value < -2147483648 || tmp->next->value > 2147483647)
		{
			while (j <= i && stack)
			{
				tmp = stack;
				stack = stack->next;
				clear_node(tmp);
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (stack);
}

int	check_status(t_stack *stack, int len)
{
	int		i;
	int		j;
	t_stack	*tmp1;
	t_stack	*tmp2;

	i = 0;
	tmp1 = stack;
	tmp2 = stack->next;
	while (i < len)
	{	
		j = i + 1;
		while (j < len)
		{
			if (tmp1->value == tmp2->value)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	tmp2 = stack->next;
}

int	main(int argc, char **argv)
{	
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				len_a;
	int				len_b;

	if (argc < 2)
		return (0);
	if (check_parameters(argv, argc) != 0)
		return (0);
	stack_a = stack_generator(argc, argv);
	if (stack_a == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_b = 0;
	len_a = argc - 1;
	len_b = 0;
	

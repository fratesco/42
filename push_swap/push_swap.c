/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:47:50 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/17 12:01:06 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_parameters(char **params, int num)
{
	int	i;

	if (num < 2)
		return (-1);
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

t_stack	*stack_generator(int len, char **argv, int i)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		j;

	j = 0;
	stack = new(ft_atoi(argv[i++]));
	tmp = stack;
	while (i < len)
	{
		tmp->next = new(ft_atoi(argv[i++]));
		if (tmp->next->value < -2147483648 || tmp->next->value > 2147483647)
		{
			while (j++ <= i && stack)
			{
				tmp = stack;
				stack = stack->next;
				clear_node(&tmp);
			}
			ft_printf("Error\n");
			exit(0);
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
	while (i++ < len - 1)
	{	
		j = i;
		while (j++ < len)
		{
			if (tmp1->value == tmp2->value)
			{
				ft_printf("Error\n");
				exit (0);
			}
			if ((tmp2->next) != 0)
				tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{	
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (check_parameters(argv, argc) != 0)
		return (0);
	stack_a = stack_generator(argc, argv, 1);
	check_status(stack_a, stack_size(stack_a));
	stack_b = 0;
	visualize_stack(stack_a);
	//push(&stack_b, &stack_a);
	//push(&stack_b, &stack_a);
	reverse_rotate(&stack_a);
	visualize_stack(stack_a);
	visualize_stack(stack_b);
	while (stack_a != 0)
		clear_node(&stack_a);
	while (stack_b != 0)
		clear_node(&stack_b);
	return (0);
}
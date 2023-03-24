/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:25:55 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/24 11:37:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack);
	tmp2 = (*stack)->next->next;
	(*stack) = tmp->next;
	(*stack)->next = tmp;
	(*stack)->next->next = tmp2;
	indexer(stack);
}

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack2)->next;
	if (*stack1 == 0)
	{
		*stack1 = *stack2;
		(*stack1)->next = 0;
		(*stack2) = tmp1;
	}
	else
	{
		tmp2 = *stack1;
		(*stack1) = (*stack2);
		(*stack1)->next = tmp2;
		(*stack2) = tmp1;
	}
	indexer(stack1);
	indexer(stack2);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	*stack = (*stack)->next;
	tmp2 = *stack;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = 0;
	indexer(stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp2 = *stack;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp1 = tmp2->next;
	tmp2->next = 0;
	tmp1->next = (*stack);
	*stack = tmp1;
	indexer(stack);
}

void	check_one_argument(char *string)
{
	long	i;

	i = ft_atoi(string);
	if (i < -2147483648 || i > 2147483647)
	{
		ft_printf("Error\n");
		exit (0);
	}
}
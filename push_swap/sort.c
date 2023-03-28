/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:35:41 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/28 19:10:34 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	tmp2;
	int	tmp3;

	tmp2 = (*stack)->next->value;
	tmp3 = (*stack)->next->next->value;
	if (((*stack)->value > tmp2) && ((*stack)->value > tmp3))
	{
		if (tmp3 > tmp2)
			rotate(stack, 'a');
		else
		{
			swap(stack, 'a');
			reverse_rotate(stack, 'a');
		}
	}
	else if ((*stack)->value < tmp2 && (*stack)->value < tmp3)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if ((*stack)->value > tmp2 && tmp2 < tmp3)
		swap(stack, 'a');
	else
		reverse_rotate(stack, 'a');
}

void	sort_4(t_stack **stack1, t_stack **stack2)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = (*stack1)->value;
	tmp2 = (*stack1)->next->value;
	tmp3 = (*stack1)->next->next->value;
	tmp4 = (*stack1)->next->next->next->value;
	if (tmp1 < tmp2 && tmp1 < tmp3 && tmp1 < tmp4)
	{
	}
	else if (tmp2 < tmp1 && tmp2 < tmp3 && tmp2 < tmp4)
		rotate(stack1, 'a');
	else if (tmp3 < tmp1 && tmp3 < tmp2 && tmp3 < tmp4)
	{
		rotate(stack1, 'a');
		rotate(stack1, 'a');
	}
	else
		reverse_rotate(stack1, 'a');
	push(stack2, stack1, 'b');
	sort_3(stack1);
	push(stack1, stack2, 'a');
}

void	sort_5(t_stack **stack1, t_stack **stack2)
{
	push(stack2, stack1, 'b');
	push(stack2, stack1, 'b');
	sort_3(stack1);
	while (check_order(*stack1) || *stack2)
	{
		if (!(*stack2))
			break ;
		if (*stack2 && (*stack2)->index == ((*stack1)->index - 1))
			push(stack1, stack2, 'a');
		else if (*stack2 && (*stack2)->index > (*stack1)->index)
			rotate(stack1, 'a');
		else if (*stack2 && (*stack2)->index < (*stack1)->index)
			reverse_rotate(stack1, 'a');
	}
	while (check_order(*stack1))
	{
		if ((*stack1)->index > (*stack1)->next->index)
			rotate(stack1, 'a');
		else
			reverse_rotate(stack1, 'a');
	}
}

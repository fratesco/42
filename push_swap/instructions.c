/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:25:55 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/16 17:36:00 by fgolino          ###   ########.fr       */
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
}

void	rotate(t_stack **stack)
{
	
}

void	reverse_rotate(long **stack, int len)
{
	int	buffer;

	buffer = (*stack)[len - 1];
	len--;
	while (len > 0)
	{
		(*stack)[len] = (*stack)[len - 1];
		len--;
	}
	(*stack)[0] = buffer;
	ft_printf("rr");
}

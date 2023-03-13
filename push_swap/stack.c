/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:14:44 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/13 17:22:42 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new(int value)
{
	t_stack			*stack;
	size_t			len;
	int				i;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->value = value;
	stack->biggest = 0;
	stack->next = 0;
	return (stack);
}

void	clear_node(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);
}

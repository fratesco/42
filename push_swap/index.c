/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:00:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/21 15:00:33 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_biggest(t_stack stack1, t_stack *stack2)
{
	int	i;

	i = 0;
	if (stack1.value > stack2->value)
		return (i);
	stack2 = stack2->next;
	i++;
	while (stack2)
	{
		if (stack1.value > stack2->value)
			return (i);
		stack2 = stack2->next;
		i++;
	}
	return (i);
}

int	count_moves_smalles(t_stack stack1, t_stack *stack2)
{
	int	i;

	i = 0;
	if (stack1.value < stack2->value)
		return (i);
	stack2 = stack2->next;
	i++;
	while (stack2)
	{
		if (stack1.value < stack2->value)
			return (i);
		stack2 = stack2->next;
		i++;
	}
	return (i);
}

int	position_moves()
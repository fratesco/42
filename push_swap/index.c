/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:00:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/24 11:31:19 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_new_biggest(t_stack stack1, t_stack *stack2)
{
	int	i;

	i = 0;
	while (stack2)
	{
		if (stack2->biggest == 1)
			return (i);
		i++;
		stack2 = stack2->next;
	}
}

int	count_moves(t_stack stack1, t_stack *stack2)
{
	int	i;

	i = 0;

	while (stack2)
	{
		
	}
}
int	position_moves()
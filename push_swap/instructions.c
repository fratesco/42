/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:25:55 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/09 13:08:39 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(long **stack)
{
	int	num;

	num = stack[0][0];
	stack[0][0] = stack[0][1];
	stack[0][1] = num;
}

void	push(long **stack_a, long **stack_b, int *len_a, int *len_b)
{
	int	i;

	i = 0;
	if (*len_b == 0)
		return ;
	(*stack_a)[(*len_b) - 1] = (*stack_b)[0];
	while (i < len_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	*len_b -= 1;
	*len_a += 1;
}

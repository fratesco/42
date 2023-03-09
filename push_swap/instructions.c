/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:25:55 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/09 12:24:14 by fgolino          ###   ########.fr       */
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

void	push(long **stack_a, long **stack_b, int len_a, int len_b)
{
	int	i;

	if (len_b == 0)
		return ;
	while ()
	{
		
	}
}
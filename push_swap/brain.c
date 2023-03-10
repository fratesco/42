/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:59 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/10 18:36:31 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algorithm(long **stack_a, long **stack_b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (check_status(*stack_a, len_a) || len_b)
	{
		
	}
}

void	sort_3(long **stack, int len)
{
	if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]) &&
	((*stack)[1] > (*stack)[2]))
	{
		rotate(stack, len);
		//gestisci lista comandi
		swap(stack);
		//lista comandi
	}
	else if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]) &&
	((*stack)[1] < (*stack)[2]))
	{
		rotate(stack, len);
		//lista comandi
	}
	else if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]) &&
	((*stack)[1] < (*stack)[2]))
}
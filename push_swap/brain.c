/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:59 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/13 16:33:40 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_efficient(long **stack1, long **stack2, int *len1, int *len2)
{
	int	moves;
	int	tmp;
	int	i;
	int	pos;

	moves = 0;
	i = 0;
	while (i < len1)
	{
		
		if (tmp < moves)
			pos = i;
	}
	
}

void	sorting_algo(long **stack_a, long **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (check_status(*stack_a, *len_a) && (len_a > 3))
	{
		push(stack_b, stack_a, len_b, len_a);
		push(stack_b, stack_a, len_b, len_a);
		ft_printf("pb\npb\n");
		while (len > 3)
		{
			
		}
	}
	sort_5(stack_a, stack_b, len_a, len_b);
}

void	sort_3(long **stack, int *len)
{
	if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]) &&
	((*stack)[1] > (*stack)[2]))
	{
		rotate(stack, *len);
		swap(stack);
		ft_printf("a\n");
	}
	else if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]) &&
	((*stack)[1] < (*stack)[2]))
		rotate(stack, len);
	else if (((*stack)[0] < (*stack)[1]) && ((*stack)[0] < (*stack)[2]) &&
	((*stack)[1] > (*stack)[2]))
	{
		swap(stack);
		rotate(stack, *len);
		ft_printf("a\n");
	}
	else if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] < (*stack)[2]) &&
	((*stack)[1] < (*stack)[2]))
		swap(stack);
	else
		reverse_rotate(stack, len);
	ft_printf("a\n");
}

//void	sort_5(long **stack_a, long **stack_b, int *len_a, int *len_b)
//{
//	push(stack_b, stack_a, len_b, len_a);
//	ft_printf("b\n");
//	push(stack_b, stack_a, len_b, len_a);
//	ft_printf("b\n");
//	if (check_status(stack_a, len_a) != 0)
//		sort_3(stack_a, len_a);
//	if (check_status(stack_b, len_b) != 0)
//	{
//		swap(stack_b);
//		ft_printf("b\n");
//	}
//	push(stack_a, stack_b, len_a, len_b);
//	ft_printf("a\n");
//	push(stack_a, stack_b, len_a, len_b);
//	ft_printf("a\n");
//}
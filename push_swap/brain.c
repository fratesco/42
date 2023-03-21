/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:59 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/21 15:02:12 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_efficient(t_stack *stack1, t_stack *stack2)
{
	//dobbiamo sempre controllare se il numero che stiamo spostando da stack1 è un nuovo massimo o monimo per stack2
	//in quel caso il numero di mosse necessarie per preparare stack2 è zero
}

void	find_biggest(t_stack **stack)
{
	t_stack	*buff;
	t_stack	*tmp;

	buff = *stack;
	tmp = (*stack)->next;
	while (tmp)
	{
		if (tmp->value > buff->value)
			buff = tmp;
		else
			tmp->biggest = 0;
		tmp = tmp->next;
	}
	buff->biggest = 1;
	buff = *stack;
	tmp = (*stack)->next;
	while (tmp)
	{
		if (tmp->value < buff->value)
			buff = tmp;
		tmp = tmp->next;
	}
	buff->biggest = -1;
}
//void	sorting_algo(long **stack_a, long **stack_b, int *len_a, int *len_b)
//{
//	int	i;
//	int	tmp;
//
//	i = 0;
//	tmp = 0;
//	while (check_status(*stack_a, *len_a) && (*len_a > 3))
//	{
//		push(stack_b, stack_a, len_b, len_a);
//		push(stack_b, stack_a, len_b, len_a);
//		ft_printf("pb\npb\n");
//		while (len_a > 3)
//		{
//			
//		}
//	}
//	
//}

void	sort_3(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (check_status(*stack, stack_size(*stack)) == 1)
		return ;
	else if (tmp->biggest == 1)
	{
		if (tmp->next->value < tmp->next->next->value)
		{
			rotate(stack);
			ft_printf("ra\n");
		}
		else
		{
			rotate(stack);
			swap(stack);
			ft_printf("ra\nsa\n");
		}
	}
	else
		sort_rest(stack);
}

void	sort_rest(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	if (tmp->biggest == 1)
	{
		if (tmp->next->value > (*stack)->value)
		{
			reverse_rotate(stack);
			swap(stack);
			ft_printf("rra\nsa\n");
		}
		else
		{
			reverse_rotate(stack);
			ft_printf("rra\n");
		}
	}
	else
	{
		swap(stack);
		ft_printf("sa\n");
	}
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
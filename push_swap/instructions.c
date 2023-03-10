/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:25:55 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/10 18:38:13 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(long **stack)
{
	int	num;

	num = stack[0][0];
	stack[0][0] = stack[0][1];
	stack[0][1] = num;
	//aggiungi comando nella lista
}

void	push(long **stack_a, long **stack_b, int *len_a, int *len_b)
{
	int	i;

	i = (*len_a) - 1;
	if (*len_b == 0)
		return ;
	while (i >= 0)
	{
		(*stack_a)[i + 1] = (*stack_a)[i];
		i--;
	}
	(*stack_a)[0] = (*stack_b)[0];
	i = 0;
	while (i < (*len_b) - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	*len_b -= 1;
	*len_a += 1;
	//aggiungi comando nella lista
}

void	rotate(long **stack, int len)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = (*stack)[0];
	while (i < len - 1)
	{
		(*stack)[i] = (*stack)[i + 1];
		i++;
	}
	(*stack)[len - 1] = buffer;
	//aggiungi comando nella lista
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
	//aggiungi comando nella lista
}

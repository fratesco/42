/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:59 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/29 10:58:58 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_biggest(t_stack **stack)
{
	t_stack	*buff;
	t_stack	*tmp;
	int		size;

	size = stack_size(*stack);
	while (size)
	{
		buff = (*stack);
		while (buff->index != 0)
			buff = buff->next;
		tmp = (*stack);
		while (tmp)
		{
			if ((tmp->value > buff->value) && tmp->index == 0)
				buff = tmp;
			tmp = tmp->next;
		}
		buff->index = size--;
	}
}

void	how_to_sort(t_stack **stack1, t_stack **stack2)
{
	if (stack_size(*stack1) == 2)
		swap(stack1, 'a');
	if (stack_size(*stack1) == 3)
		sort_3(stack1);
	else if (stack_size(*stack1) == 4)
		sort_4(stack1, stack2);
	else if (stack_size(*stack1) == 5)
		sort_5(stack1, stack2);
	else
		sorter(stack1, stack2);
}

void	sorter(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	i = 0;
	while (check_order(*stack1))
	{
		tmp = *stack1;
		tmp2 = 0;
		while (tmp && (tmp2 != tmp))
		{
			if (((tmp->index >> i) & 1) == 1)
			{
				if (tmp2 == 0)
					tmp2 = tmp;
				rotate(stack1, 'a');
			}
			else
				push(stack2, stack1, 'b');
			tmp = *stack1;
		}
		mega_pusher(stack1, stack2);
		i++;
	}
}

void	mega_pusher(t_stack **stack1, t_stack **stack2)
{
	while (*stack2)
		push(stack1, stack2, 'a');
}

t_stack	*string_argument(char *str)
{
	char	**tmp;
	int		i;
	t_stack	*buffer;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	if (check_parameters(tmp, i) != 0)
	{
		while (i >= 0)
			free(tmp[i--]);
		exit(0);
	}
	buffer = (stack_generator(i, tmp, 0));
	while (i >= 0)
		free(tmp[i--]);
	free(tmp);
	return (buffer);
}

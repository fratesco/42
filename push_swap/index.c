/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:00:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/13 16:47:58 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves(int num, long *stack, int len1, int len2)
{
	int	moves;
	int	i;

	i = 0;
	while (i < len2)
	{
		if (num < stack[i])
		{
			i = 0;
			break ;
		}
		i++;
	}
	if (i == len2)
		return (1);
	
}

int	position_moves(num, )
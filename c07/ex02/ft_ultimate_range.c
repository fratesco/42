/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:23:17 by fgolino           #+#    #+#             */
/*   Updated: 2022/11/02 14:54:27 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*temp;

	if (min >= max)
		return (0);
	size = (unsigned int)(max - min);
	temp = (int *)malloc(size * sizeof(int));
	if (!(range))
		return (-1);
	i = 0;
	while (i < size && min < max)
	{
		temp[i] = min;
		min++;
		i++;
	}
	*range = temp;
	return (size);
}

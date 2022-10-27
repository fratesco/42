/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:23:17 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/27 18:34:53 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_utltimate_range(int **range, int min, int max)
{
	int	size;
	int	*vec;
	int	i;

	if (min >= max)
		return (0);
	size = (unsigned int)(max - min);
	range = (int **)malloc(1 * sizeof(int *));
	vec = (int *)malloc(size * sizeof(int));
	if (!(range || vec))
		return (-1);
	i = 0;
	while (i < size && min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (size);
}

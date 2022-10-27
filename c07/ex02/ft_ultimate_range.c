/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:23:17 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/27 18:02:54 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_utltimate_range(int **range, int min, int max)
{
	int	range;
	int	*vec;
	int	i;

	if (min >= max)
		return (0);
	range = (unsigned int)(max - min);
	vec = malloc(range * sizeof(int));
	i = 0;
	while (i < range && min < max)
	{
		vec[i] = min;
		min++;
		i++;
	}
	return (vec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:46:14 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/14 11:09:20 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_items(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	coll;
	int	start;

	i = 0;
	exit = 0;
	coll = 0;
	start = 0;
	while (map[i])
	{
		j = 0;
		while (map[i++][j])
		{
			if (map[i][j] == 'C')
				coll++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				start++;
			j++;
		}
	}
	return (check_more(exit, coll, start));
}

int	check_more(int exit, int coll, int start)
{
	if (exit == 0 || coll == 0 || start == 0)
		return (1);
	if (start > 1)
		return (1);
	return (0);
}

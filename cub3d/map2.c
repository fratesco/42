/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:11:13 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/08 15:55:41 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_lines(char *str, int start, int raw)
{
	int	i;

	i = 0;
	while (str && str[start + i])
	{
		if ((raw == 0 || i == 0) && str[start] != '1')
			return (1);
		else if ((str[start + i] == '\n' || !str[start + i])
			&& str[start + i] != '1')
			return (1);
		else if (str[start + i] == ' ')
		{
			i++;
			continue;
			//controllare sotto sopra e a destra
		}
		else if (str[start + i] != 'N' && str[start + i] != 'W'
			&& str[start + i] != 'E' && str[start + i] != 'S'
			&& str[start + i] != '0' && str[start + i] != '1')
			return (1);
		i++;
	}
	if (str && (str[start + i - 1] != '1' || str[start] == 0))
		return (1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:57:28 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/19 12:53:06 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size(char **map, int height)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i <= height)
	{
		if (len)
		{
			if (len != ft_strlen(map[i]))
				return (1);
		}
		else
			len = ft_strlen(map[1]);
		i++;
	}
	return (0);
}

void	invalid_item(char **map, int len, int height)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i <= height)
	{
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'E'
				&& c != 'S' && c != 'P' && c != 'C')
			{
				ft_printf("%i %i", i, j);
				ft_printf("Error\nInvalid Map Character\n");
				map_freerer(map);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	get_positions(t_game *game, char **map)
{
	int	i;
	int	j;
	int	coins;
	int	exits;

	i = 0;
	coins = 0;
	exits = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->lenght)
		{
			if (map[i][j] == 'C')
			{
				ft_printf("qui");
				game->coins->x[coins] = j;
				game->coins->y[coins] = i;
				coins++;
			}
			j++;
		}
		i++;
	}
}


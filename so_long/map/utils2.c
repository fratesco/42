/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:57:28 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/28 17:42:01 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	invalid_item(char **map, int len, int height, t_game *game)
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
				ft_printf("Error\nInvalid Map Character\n");
				game_freerer(game, map);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	get_positions(t_game *game, char **map, int exits)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->lenght)
		{
			if (map[i][j] == 'C')
				get_coin(game, j, i);
			else if (map[i][j] == 'E')
			{
				game->exit_x[game->exits] = j;
				game->exit_y[game->exits] = i;
				game->exits += 1;
			}
			else if (map[i][j] == 'P')
				get_player(game, j, i);
			else if (map[i][j] == 'N')
				get_enemy(game, j, i, 0);
			j++;
		}
		i++;
	}
}

void	get_coin(t_game *game, int x, int y)
{
	game->coins->x[game->coins->num] = x;
	game->coins->y[game->coins->num] = y;
	game->coins->num += 1;
	game->coins->max_num += 1;
	game->coins->animation_step = 0;
}

void	get_player(t_game *game, int x, int y)
{
	game->player->start_x = x;
	game->player->start_y = y;
	game->player->x = x;
	game->player->y = y;
	game->player->velocity = STILL;
	game->player->status = 0;
}

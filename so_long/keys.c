/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:27:38 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/28 17:42:08 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_movement(t_game *game)
{
	int	position;
	int	i;

	i = 0;
	position = game->player->y - 1;
	if (position >= 0 && (game->map[position][game->player->x] == 'N'))
	{
		mlx_string_put(game->mlx, game->wind, (((game->lenght / 2) - 2) * 32),
			(game->height * 32), 16777215, "YOU DIED");
		game->player->status = -1;
	}
	if (position >= 0 && (game->map[position][game->player->x] == 'E'
		&& game->coins->num > 0))
	{
		mlx_string_put(game->mlx, game->wind, ((game->lenght - 2) * 32),
			(game->height * 32), 16777215, "CLOSED");
	}
	else if (position >= 0 && game->map[position][game->player->x] != '1' )
	{
		game->player->velocity = UP;
		game->player->y = position;
	}
}

void	down_movement(t_game *game)
{
	int	position;
	int	i;

	i = 0;
	position = game->player->y + 1;
	if (position >= 0 && (game->map[position][game->player->x] == 'N'))
	{
		mlx_string_put(game->mlx, game->wind, (((game->lenght / 2) - 2) * 32),
			(game->height * 32), 16777215, "YOU DIED");
		game->player->status = -1;
	}
	if (position >= 0 && (game->map[position][game->player->x] == 'E'
		&& game->coins->num > 0))
	{
		mlx_string_put(game->mlx, game->wind, ((game->lenght - 2) * 32),
			(game->height * 32), 0xFFFFFF, "CLOSED");
	}
	else if (position >= 0 && game->map[position][game->player->x] != '1')
	{
		game->player->velocity = DOWN;
		game->player->y = position;
	}
}

void	left_movement(t_game *game)
{
	int	position;
	int	i;

	i = 0;
	position = game->player->x - 1;
	if (position >= 0 && (game->map[game->player->y][position] == 'N'))
	{
		mlx_string_put(game->mlx, game->wind, (((game->lenght / 2) - 2) * 32),
			(game->height * 32), 16777215, "YOU DIED");
		game->player->status = -1;
	}
	if (position >= 0 && (game->map[game->player->y][position] == 'E'
		&& game->coins->num > 0))
	{
		mlx_string_put(game->mlx, game->wind, ((game->lenght - 2) * 32),
			(game->height * 32), 16777215, "CLOSED");
	}
	else if (position >= 0 && game->map[game->player->y][position] != '1')
	{
		game->player->velocity = LEFT;
		game->player->x = position;
	}
}

void	right_movement(t_game *game)
{
	int	position;
	int	i;

	i = 0;
	position = game->player->x + 1;
	if (position >= 0 && (game->map[game->player->y][position] == 'N'))
	{
		mlx_string_put(game->mlx, game->wind, (((game->lenght / 2) - 2) * 32),
			(game->height * 32), 16777215, "YOU DIED");
		game->player->status = -1;
	}
	if (position >= 0 && (game->map[game->player->y][position] == 'E'
		&& game->coins->num > 0))
	{
		mlx_string_put(game->mlx, game->wind, ((game->lenght - 2) * 32),
			(game->height * 32), 16777215, "CLOSED");
	}
	else if (position >= 0 && game->map[game->player->y][position] != '1')
	{
		game->player->velocity = RIGHT;
		game->player->x = position;
	}
}

int	key_handler(int key, t_game *game)
{
	int	i;

	i = 4;
	while (i-- >= 0)
	{
		mlx_string_put(game->mlx, game->wind, ((game->lenght - 2) * 32),
			(game->height * 32), 0, "CLOSED");
	}
	if (key == 53)
		close_game(game);
	else if (key == 15)
		reset_game(game);
	if (game->player->status == -1)
		return (0);
	else if (key == 13)
		up_movement(game);
	else if (key == 0)
		left_movement(game);
	else if (key == 1)
		down_movement(game);
	else if (key == 2)
		right_movement(game);
	else if (key == 53)
		close_game(game);
	return (0);
}

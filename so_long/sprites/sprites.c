/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:26:07 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/24 16:50:33 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_handler(t_game *game)
{	
	int	pix;
	int	i;
	int	j;

	i = 0;
	j = 0;
	pix = PIXELS;
	if (game->frame == 0)
	{
		game->walls_sprite
			= mlx_xpm_file_to_image(game->mlx, WALLS, &pix, &pix);
		game->coins->sprite[0]
			= mlx_xpm_file_to_image(game->mlx, COLLECTIBLE, &pix, &pix);
		game->player->sprite
			= mlx_xpm_file_to_image(game->mlx, PLAYER, &pix, &pix);
		game->terrain_sprite
			= mlx_xpm_file_to_image(game->mlx, TERRAIN, &pix, &pix);
	}
	print_game_start(game, pix, i, j);
}

void	print_game_start(t_game *game, int pix, int i, int j)
{
	while (game->map[i] && game->frame == 0)
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->wind,
				game->terrain_sprite, (j * pix), (i * pix));
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->walls_sprite, (j * pix), (i * pix));
			else if (game->map[i][j] != '1')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->terrain_sprite, (j * pix), (i * pix));
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->player->sprite, (j * pix), (i * pix));
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->coins->sprite[0], (j * pix), (i * pix));
			j++;
		}
		i++;
	}
}

int	image_handler(t_game *game)
{
	int	x;
	int	y;

	if (game->game_iteration == 0)
		xpm_handler(game);
	game->frame += 1;
	if (game->player->velocity != STILL)
	{
		x = game->player->x;
		y = game->player->y;
		mlx_put_image_to_window(game->mlx, game->wind,
			game->player->sprite, (32 * x), (32 * y));
		velocity_handler(game, x, y);
		coins_handler(game, x, y);
		if (game->coins->num == 0)
			exit_handler(game, x, y);
	}
	return (0);
}

void	coins_handler(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->coins->num)
	{
		if (x == game->coins->x[i] && y == game->coins->y[i])
		{
			game->coins->x[i] = -1;
			game->coins->y[i] = -1;
			game->coins->num -= 1;
		}
		i++;
	}
}

void	velocity_handler(t_game *game, int x, int y)
{
	if (game->player->velocity == UP)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * x), (32 * (y + 1)));
	}
	else if (game->player->velocity == DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * x), (32 * (y - 1)));
	}
	else if (game->player->velocity == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * (x + 1)), (32 * y));
	}
	else if (game->player->velocity == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * (x - 1)), (32 * y));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:26:07 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/02 15:52:28 by fgolino          ###   ########.fr       */
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
		game->exit_sprite
			= mlx_xpm_file_to_image(game->mlx, EXIT, &pix, &pix);
		game->enemy->sprite
			= mlx_xpm_file_to_image(game->mlx, ENEMY, &pix, &pix);
		mlx_string_put(game->mlx, game->wind, 64,
			(game->height * 32), 16777215, "0");
	}
	print_game_start(game, pix, i, j);
}

void	print_game_start(t_game *game, int pix, int i, int j)
{
	while (game->map[i] && game->frame == 0)
	{
		game->coins->sprite[1]
			= mlx_xpm_file_to_image(game->mlx, COLLECTIBLE2, &pix, &pix);
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->wind,
				game->terrain_sprite, (j * pix), (i * pix));
			if (game->map[i][j] != '0')
				load_stuff(game, i, j, pix);
			j++;
		}
		i++;
		mlx_string_put(game->mlx, game->wind, 0,
			(game->height * 32), 16777215, "MOVES: ");
	}
}

int	image_handler(t_game *game)
{
	int		x;
	int		y;
	char	*tmp;

	if (game->game_iteration == 0)
		xpm_handler(game);
	game->frame += 1;
	animation(game, game->coins, 32);
	if (game->player->velocity != STILL)
	{
		x = game->player->x;
		y = game->player->y;
		mlx_put_image_to_window(game->mlx, game->wind,
			game->player->sprite, (32 * x), (32 * y));
		velocity_handler(game, x, y);
		coins_handler(game, x, y);
		game->moves++;
		if (game->coins->num == 0)
			exit_handler(game, x, y);
		tmp = ft_itoa(game->moves);
		mlx_string_put(game->mlx, game->wind, 64,
			(game->height * 32), 16777215, tmp);
		free(tmp);
	}
	return (0);
}

void	coins_handler(t_game *game, int x, int y)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->wind, 64,
		(game->height * 32), 0, tmp);
	free(tmp);
	while (i < game->coins->max_num)
	{
		if (x == game->coins->x[i] && y == game->coins->y[i])
		{
			game->coins->x[i] = -1;
			game->coins->y[i] = -1;
			game->coins->num -= 1;
		}
		i++;
	}
	game->coins->flag = 0;
}

void	velocity_handler(t_game *game, int x, int y)
{
	if (game->player->velocity == UP)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * x), (32 * (y + 1)));
		game->player->velocity = STILL;
	}
	else if (game->player->velocity == DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * x), (32 * (y - 1)));
		game->player->velocity = STILL;
	}
	else if (game->player->velocity == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * (x + 1)), (32 * y));
		game->player->velocity = STILL;
	}
	else if (game->player->velocity == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->wind,
			game->terrain_sprite, (32 * (x - 1)), (32 * y));
		game->player->velocity = STILL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:38:09 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/02 16:54:14 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_enemy(t_game *game, int x, int y, int enemy)
{
	if (game->enemy->x == 0)
	{
		game->enemy->x = (int *)malloc(enemy * sizeof(int));
		game->enemy->y = (int *)malloc(enemy * sizeof(int));
	}
	else if (x > -1 && y > -1)
	{
	game->enemy->x[game->enemy->num] = x;
	game->enemy->y[game->enemy->num] = y;
	game->enemy->num += 1;
	}
}

void	load_stuff(t_game *game, int i, int j, int pix)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->wind,
			game->walls_sprite, (j * pix), (i * pix));
	if (game->map[i][j] == 'N')
		mlx_put_image_to_window(game->mlx, game->wind,
			game->enemy->sprite, (j * pix), (i * pix));
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->wind,
			game->exit_sprite, (j * pix), (i * pix));
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->wind,
			game->player->sprite, (j * pix), (i * pix));
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->wind,
			game->coins->sprite[0], (j * pix), (i * pix));
}

void	animation(t_game *game, t_coin *coins, int p)
{
	int	i;

	i = 0;
	while (i < game->coins->max_num)
	{
		if (game->coins->x[i] != -1)
		{
			if (coins->animation_step % 6 == 0)
			{
				mlx_put_image_to_window(game->mlx, game->wind,
					game->terrain_sprite, (coins->x[i] * p), (coins->y[i] * p));
				mlx_put_image_to_window(game->mlx, game->wind, coins->sprite[0],
					(game->coins->x[i] * 32), (game->coins->y[i] * 32));
			}
			else
			{
				mlx_put_image_to_window(game->mlx, game->wind, coins->sprite[1],
					(game->coins->x[i] * 32), (game->coins->y[i] * 32));
			}
		}
		game->coins->animation_step++;
		i++;
	}
}

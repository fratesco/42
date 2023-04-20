/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:26:07 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/20 18:21:55 by fgolino          ###   ########.fr       */
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
	game->walls_sprite
		= mlx_xpm_file_to_image(game->mlx, WALLS, &pix, &pix);
	game->coins->sprite[0]
		= mlx_xpm_file_to_image(game->mlx, COLLECTIBLE, &pix, &pix);
	game->player->sprite
		= mlx_xpm_file_to_image(game->mlx, PLAYER, &pix, &pix);
	game->terrain_sprite
		= mlx_xpm_file_to_image(game->mlx, TERRAIN, &pix, &pix);
	print_game_start(game, pix, i, j);
}

void	print_game_start(t_game *game, int pix, int i, int j)
{
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->wind,
				game->terrain_sprite, (j * pix), (i * pix));
			ft_printf("%i", j);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->walls_sprite, (j * pix), (i * pix));
			else if (game->map[i][j] != '1')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->terrain_sprite, (j * pix), (i * pix));
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->player->sprite, (j * pix), (i * pix));
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->wind,
					game->coins->sprite[0], (j * pix), (i * pix));
			j++;
		}
		i++;
	}
}

int	image_handler(t_game *game)
{

	if (game->game_iteration == 0)
		xpm_handler(game);
	return (0);
}
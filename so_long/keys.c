/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:27:38 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/23 16:39:51 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_movement(t_game *game)
{
	int	position;
	int	i;

	i = 0;
	position = game->player->x - game->lenght;
	if (position >= 0 && game->map[game->player->y][position] != '1')
		game->player->velocity = UP;
	if (position >= 0 && game->map[game->player->y][position] == 'C')
	{
		while (i <= num)
		{
			if (game->player->x == game->coins->x[i] && game->player->y == game->coins->y[i])
		}
	}
		
}

int	key_handler(int key, t_game *game)
{
	if (key == 13)
		up_movement(game);
	return (0);
}

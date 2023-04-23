/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:27:38 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/23 15:42:12 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_movement(t_game *game)
{
	game->player->velocity = 1;
}

int	key_handler(int key, t_game *game)
{
	if (key == 13)
		up_movement(game);
	return (0);
}

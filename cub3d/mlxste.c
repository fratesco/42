/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxste.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:23 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/09 19:17:56 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_handler(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1280,
			720, "CUB3D");
	mlx_key_hook(data->window, keys_controls, data);
	//mlx_hook(data->window, 17, 0, close_game, (void *)data);
	mlx_loop_hook(data->mlx, nullifiereee, data);
	mlx_loop(data->mlx);
}

int	nullifiereee(void)
{
    return (0);
}
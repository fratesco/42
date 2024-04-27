/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxste.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:23 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/27 09:36:37 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_handler(t_data *data)
{
	data->window = mlx_new_window(data->mlx, data->res_w,
			data->res_h, "CUB3D");
	mlx_key_hook(data->window, keys_control, data);
	mlx_hook(data->window, 17, 0, close_game, (void *)data);
	mlx_loop_hook(data->mlx, nullifiereee, (void *)data);
	mlx_loop(data->mlx);
}

int	close_game(void *data)
{
	freerer((t_data *)data);
	exit (0);
}

int	nullifiereee(void *data)
{
	t_data	*tmp;

	tmp = (t_data *)data;
	raycasting(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->window, tmp->image.img, 0, 0);
	return (0);
}

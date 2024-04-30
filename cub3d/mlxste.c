/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxste.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:23 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/30 21:27:22 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_handler(t_data *data)
{
	data->window = mlx_new_window(data->mlx, data->res_w,
			data->res_h, "CUB3D");
	mlx_mouse_get_pos(data->mlx, data->window, &data->def_x, &data->def_y);
	mlx_hook(data->window, 2, 1L << 0, keys_control_movements, data);
	mlx_hook(data->window, 3, 1L << 1, keys_control_released, data);
	mlx_hook(data->window, 17, 0, close_game, (void *)data);
	mlx_loop_hook(data->mlx, nullifiereee, (void *)data);
	mlx_loop(data->mlx);
}

int	close_game(void *data)
{
	t_data	*tmp;

	tmp = (t_data *)data;
	freerer(tmp);
	exit (0);
}

int	nullifiereee(void *data)
{
	t_data	*tmp;

	tmp = (t_data *)data;
	check_movement(tmp);
	mlx_mouse_get_pos(tmp->mlx, tmp->window, &tmp->mouse_x, &tmp->mouse_y);
	turn_mouse(data);
	raycasting(tmp);
	add_minimap(data);
	mlx_put_image_to_window(tmp->mlx, tmp->window, tmp->image.img, 0, 0);
	return (0);
}

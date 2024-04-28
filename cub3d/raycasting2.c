/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:24:50 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/28 22:58:50 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_x(t_data *data)
{
	if (data->side == X)
		data->wall_x = data->player->y + data->ray.perpwall_dist
			* data->ray.ray_dir_y;
	if (data->side == Y)
		data->wall_x = data->player->x + data->ray.perpwall_dist
			* data->ray.ray_dir_x;
	data->wall_x -= floor(data->wall_x);
}

void	get_start_end(t_data *data)
{
	data->ray.draw_start = (data->res_h / 2) - (data->line_height / 2);
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = (data->res_h / 2) + (data->line_height / 2);
	if (data->ray.draw_end >= data->res_h)
		data->ray.draw_end = data->res_h - 1;
}
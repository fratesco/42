/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:56:44 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/23 11:29:06 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	while (data->z < data->res_w)
	{
		calcs(data);
		data->hit = 0;
		get_step(data);
		dda(data);
		wall_distance(data);
		calculate_wall_x(data);
		data->z++;
	}
}

void	calcs(t_data *data)
{
	data->player->camera_x = 2 * (data->z / (double)data->res_w) - 1;
	data->ray.ray_dir_x = data->ray.direct_x
		+ (data->ray.plane_x * data->player->camera_x);
	data->ray.ray_dir_y = data->ray.direct_y
		+ (data->ray.plane_y * data->player->camera_x);
	data->player->map_x = (int)floor(data->player->x);
	data->player->map_y = (int)floor(data->player->y);
	data->ray.delta_x = fabs(1 / data->ray.ray_dir_x);
	data->ray.delta_y = fabs(1 / data->ray.ray_dir_y);
	get_step(data);
}

void	get_step(t_data *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player->x - data->player->map_x)
			* data->ray.delta_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->player->x - data->player->map_x + 1)
			* data->ray.delta_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player->y - data->player->map_y)
			* data->ray.delta_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->player->y - data->player->map_y + 1)
			* data->ray.delta_y;
	}
}

void	dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_x;
			data->player->map_x += data->ray.step_x;
			data->side = X;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_y;
			data->player->map_y += data->ray.step_y;
			data->side = Y;
		}
		if (data->map[data->player->map_y][data->player->map_x] == '1')
			data->hit = 1;
	}
}

void	wall_distance(t_data *data)
{
	if (data->side == X)
		data->ray.perpwall_dist = data->ray.side_dist_x - data->ray.delta_x;
	else
		data->ray.perpwall_dist = data->ray.side_dist_y - data->ray.delta_y;
}

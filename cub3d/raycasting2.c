/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:24:50 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/23 11:28:48 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_x(t_data *data)
{
	if (data->side == X)
		data->wall_x = data->player->map_y + data->ray.perpwall_dist
			* data->ray.ray_dir_y;
	if (data->side == Y)
		data->wall_x = data->player->map_x + data->ray.perpwall_dist
			* data->ray.ray_dir_x;
	data->wall_x -= floor(data->wall_x);
}

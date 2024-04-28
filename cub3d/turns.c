/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:46:09 by fratesco          #+#    #+#             */
/*   Updated: 2024/04/28 23:09:14 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_data *data)
{
	double	tmp_dir;
	double	tmp_plane;
	double	rotate;

	tmp_dir = data->ray.direct_x;
	tmp_plane = data->ray.plane_x;
	rotate = 0.02;

	data->ray.direct_x = tmp_dir * cos(rotate)
		- data->ray.direct_y * sin(rotate);
	data->ray.direct_y = tmp_dir * sin(rotate)
		+ data->ray.direct_y * cos(rotate);
	data->ray.plane_x = tmp_plane * cos(rotate)
		- data->ray.plane_y * sin(rotate);
	data->ray.plane_y = tmp_plane * sin(rotate)
		+ data->ray.plane_y * cos(rotate);
}

void	turn_left(t_data *data)
{
	double	tmp_dir;
	double	tmp_plane;
	double	rotate;

	tmp_dir = data->ray.direct_x;
	tmp_plane = data->ray.plane_x;
	rotate = -0.02;

	data->ray.direct_x = tmp_dir * cos(rotate)
		- data->ray.direct_y * sin(rotate);
	data->ray.direct_y = tmp_dir * sin(rotate)
		+ data->ray.direct_y * cos(rotate);
	data->ray.plane_x = tmp_plane * cos(rotate)
		- data->ray.plane_y * sin(rotate);
	data->ray.plane_y = tmp_plane * sin(rotate)
		+ data->ray.plane_y * cos(rotate);
}
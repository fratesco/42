/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:46:09 by fratesco          #+#    #+#             */
/*   Updated: 2024/05/14 11:54:53 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_data *data, double rotate)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = data->ray.direct_x;
	tmp_plane = data->ray.plane_x;
	data->ray.direct_x = tmp_dir * cos(rotate)
		- data->ray.direct_y * sin(rotate);
	data->ray.direct_y = tmp_dir * sin(rotate)
		+ data->ray.direct_y * cos(rotate);
	data->ray.plane_x = tmp_plane * cos(rotate)
		- data->ray.plane_y * sin(rotate);
	data->ray.plane_y = tmp_plane * sin(rotate)
		+ data->ray.plane_y * cos(rotate);
}

void	turn_left(t_data *data, double rotate)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = data->ray.direct_x;
	tmp_plane = data->ray.plane_x;
	data->ray.direct_x = tmp_dir * cos(rotate)
		- data->ray.direct_y * sin(rotate);
	data->ray.direct_y = tmp_dir * sin(rotate)
		+ data->ray.direct_y * cos(rotate);
	data->ray.plane_x = tmp_plane * cos(rotate)
		- data->ray.plane_y * sin(rotate);
	data->ray.plane_y = tmp_plane * sin(rotate)
		+ data->ray.plane_y * cos(rotate);
}

void	turn_mouse(t_data *data)
{
	if (data->def_x > data->mouse_x)
	{
		turn_left(data, ((0.002 * (data->def_x - data->mouse_x))));
		mlx_mouse_move(data->mlx, data->window, data->def_x, data->def_y);
	}
	else if (data->def_x < data->mouse_x)
	{
		turn_right(data, (-(0.002 * (data->mouse_x - data->def_x))));
		mlx_mouse_move(data->mlx, data->window, data->def_x, data->def_y);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:38:13 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/30 21:26:42 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)floor(data->player->x)][(int)floor(
			data->player->y + 0.2 * data->ray.direct_y)] != '1')
		data->player->y += data->ray.direct_y * 0.05;
	if (data->map[(int)floor(data->player->x + 0.2
				* data->ray.direct_x)][(int)floor(data->player->y)] != '1')
		data->player->x += data->ray.direct_x * 0.05;
}

void	move_backwards(t_data *data)
{
	if (data->map[(int)floor(data->player->x)][(int)floor(
			data->player->y - 0.2 * data->ray.direct_y)] != '1')
		data->player->y -= data->ray.direct_y * 0.05;
	if (data->map[(int)floor(data->player->x - 0.2
				* data->ray.direct_x)][(int)floor(data->player->y)] != '1')
		data->player->x -= data->ray.direct_x * 0.05;
}

void	move_right(t_data *data)
{
	if (data->map[(int)floor(data->player->x)][(int)floor(
			data->player->y + 0.2 * data->ray.plane_y)] != '1')
		data->player->y += data->ray.plane_y * 0.05;
	if (data->map[(int)floor(data->player->x + 0.2
				* data->ray.plane_x)][(int)floor(data->player->y)] != '1')
		data->player->x += data->ray.plane_x * 0.05;
}

void	move_left(t_data *data)
{
	if (data->map[(int)floor(data->player->x)][(int)floor(
			data->player->y - 0.2 * data->ray.plane_y)] != '1')
		data->player->y -= data->ray.plane_y * 0.05;
	if (data->map[(int)floor(data->player->x - 0.2
				* data->ray.plane_x)][(int)floor(data->player->y)] != '1')
		data->player->x -= data->ray.plane_x * 0.05;
}

void	check_movement(t_data *data)
{
	if (data->player->m_f)
		move_forward(data);
	if (data->player->m_b)
		move_backwards(data);
	if (data->player->m_l)
		move_left(data);
	if (data->player->m_r)
		move_right(data);
	if (data->player->r_l)
		turn_left(data, -0.02);
	if (data->player->r_r)
		turn_right(data, 0.02);
}

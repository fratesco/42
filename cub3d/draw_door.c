/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:33:14 by fratesco          #+#    #+#             */
/*   Updated: 2024/05/05 18:11:32 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_door(t_data *data)
{
	int		tmp_y;
	int		pixel;
	int		tex_x;
	double	tex_pos;
	int		tex_y;

	tmp_y = data->ray.draw_start;
	tex_x = (int)(data->wall_x * (double)data->n.w);
	if (data->side == X && data->ray.ray_dir_x > 0)
		tex_x = data->n.w - tex_x - 0.5;
	data->scale = (1.0 * data->n.h / (data->line_height));
	tex_pos = (data->ray.draw_start - (data->res_h / 2)
			+ (data->line_height / 2)) * data->scale;
	while (tmp_y < data->ray.draw_end)
	{
		tex_y = (int)tex_pos & (data->n.h - 1);
		tex_pos += data->scale;
		//my_mlx_pixel_put(data, data->z, tmp_y, 0x0000ff);
		my_mlx_pixel_put(data, data->z, tmp_y,
			get_pixel(&data->door, tex_x, tex_y));
		tmp_y++;
	}
}

void	open_door(t_data *data)
{
	if (data->map[(int)floor(data->player->x + data->ray.direct_x)]
		[(int)floor(data->player->y + data->ray.direct_y)] == '2')
		data->map[(int)floor(data->player->x + data->ray.direct_x)]
		[(int)floor(data->player->y + data->ray.direct_y)] = '3';
	else if (data->map[(int)floor(data->player->x + data->ray.direct_x)]
		[(int)floor(data->player->y + data->ray.direct_y)] == '3')
		data->map[(int)floor(data->player->x + data->ray.direct_x)]
		[(int)floor(data->player->y + data->ray.direct_y)] = '2';
}

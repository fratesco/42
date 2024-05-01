/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:24:26 by fgolino           #+#    #+#             */
/*   Updated: 2024/05/01 14:32:29 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textures(t_data *data)
{
	if (data->hit == 2)
		draw_door(data);
	else if (data->side == X && data->ray.step_x < 0)
		draw_north(data);
	else if (data->side == X && data->ray.step_x > 0)
		draw_south(data);
	else if (data->side == Y && data->ray.step_y < 0)
		draw_east(data);
	else if (data->side == Y && data->ray.step_y > 0)
		draw_west(data);
}

void	draw_north(t_data *data)
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
		my_mlx_pixel_put(data, data->z, tmp_y,
			get_pixel(&data->n, tex_x, tex_y));
		tmp_y++;
	}
}

void	draw_south(t_data *data)
{
	int		tmp_y;
	int		pixel;
	int		tex_x;
	double	tex_pos;
	int		tex_y;

	tmp_y = data->ray.draw_start;
	tex_x = (int)(data->wall_x * (double)data->s.w);
	if (data->side == X && data->ray.ray_dir_x < 0)
		tex_x = data->s.w - tex_x - 1;
	data->scale = (data->s.h * 1.0) / data->line_height;
	tex_pos = (data->ray.draw_start - (data->res_h / 2)
			+ (data->line_height / 2)) * data->scale;
	while (tmp_y < data->ray.draw_end)
	{
		tex_y = (int)tex_pos & (data->s.h - 1);
		tex_pos += data->scale;
		my_mlx_pixel_put(data, data->z, tmp_y,
			get_pixel(&data->s, tex_x, tex_y));
		tmp_y++;
	}
}

void	draw_east(t_data *data)
{
	int		tmp_y;
	int		pixel;
	int		tex_x;
	double	tex_pos;
	int		tex_y;

	tmp_y = data->ray.draw_start;
	tex_x = (int)(data->wall_x * (double)data->e.w);
	if (data->side == Y && data->ray.ray_dir_y > 0)
		tex_x = data->e.w - tex_x - 1;
	data->scale = (data->e.h * 1.0) / data->line_height ;
	tex_pos = (data->ray.draw_start - (data->res_h / 2)
			+ (data->line_height / 2)) * data->scale;
	while (tmp_y < data->ray.draw_end)
	{
		tex_y = (int)tex_pos & (data->e.h - 1);
		tex_pos += data->scale;
		my_mlx_pixel_put(data, data->z, tmp_y,
			get_pixel(&data->e, tex_x, tex_y));
		tmp_y++;
	}
}

void	draw_west(t_data *data)
{
	int		tmp_y;
	int		pixel;
	int		tex_x;
	double	tex_pos;
	int		tex_y;

	tmp_y = data->ray.draw_start;
	tex_x = (int)(data->wall_x * (double)data->w.w);
	if (data->side == Y && data->ray.ray_dir_y < 0)
		tex_x = data->w.w - tex_x - 1;
	data->scale = (data->w.h * 1.0) / data->line_height;
	tex_pos = (data->ray.draw_start - (data->res_h / 2)
			+ (data->line_height / 2)) * data->scale;
	while (tmp_y < data->ray.draw_end)
	{
		tex_y = (int)tex_pos & (data->w.h - 1);
		tex_pos += data->scale;
		my_mlx_pixel_put(data, data->z, tmp_y,
			get_pixel(&data->w, tex_x, tex_y));
		tmp_y++;
	}
}

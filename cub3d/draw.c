/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:51:37 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/25 19:39:28 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (void *)data->image.addr + (y * data->image.size_line
			+ x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_texture *img, int x, int y)
{
	int	*dst;

	dst = (void *)img->addr + (y * img->size_line
			+ x * (img->bits_per_pixel / 8));
	return (*(int *)dst);
}

void	draw_vertical(t_data *data, int start, int end, int color)
{
	while (start < end)
	{
		my_mlx_pixel_put(data, data->z, start, color);
		start++;
	}
}

void	draw_c_and_f(t_data *data)
{
	draw_vertical(data, 0, data->ray.draw_start, data->ceiling_color);
	draw_vertical(data, data->ray.draw_end, data->res_h - 1, data->floor_color);
}

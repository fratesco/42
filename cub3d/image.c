/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:23:25 by fgolino           #+#    #+#             */
/*   Updated: 2024/05/09 21:59:33 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_destroyer(t_data *data, void *img)
{
	int i;

	i = 0;
	if (img)
		mlx_destroy_image(data->mlx, img);
	if (data->n.img)
		mlx_destroy_image(data->mlx, data->n.img);
	if (data->s.img)
		mlx_destroy_image(data->mlx, data->s.img);
	if (data->w.img)
		mlx_destroy_image(data->mlx, data->w.img);
	if (data->e.img)
		mlx_destroy_image(data->mlx, data->e.img);
	if (data->door.img)
		mlx_destroy_image(data->mlx, data->door.img);
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	while(i < 15)
		mlx_destroy_image(data->mlx, data->frames[i++].img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}

int	create_images(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx, data->res_w, data->res_h);
	if (!data->image.img)
		return (printf("Error while creating mlx images!\n"));
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.size_line,
			&data->image.endian);
	data->n.addr = mlx_get_data_addr(data->n.img, &data->n.bits_per_pixel,
			&data->n.size_line, &data->n.endian);
	data->s.addr = mlx_get_data_addr(data->s.img, &data->s.bits_per_pixel,
			&data->s.size_line, &data->s.endian);
	data->w.addr = mlx_get_data_addr(data->w.img, &data->w.bits_per_pixel,
			&data->w.size_line, &data->w.endian);
	data->e.addr = mlx_get_data_addr(data->e.img, &data->e.bits_per_pixel,
			&data->e.size_line, &data->e.endian);
	data->door.addr = mlx_get_data_addr(data->door.img,
			&data->door.bits_per_pixel, &data->door.size_line,
			&data->door.endian);
	initialize_animation(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:13:03 by fgolino           #+#    #+#             */
/*   Updated: 2024/05/09 22:41:33 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_text_path(t_data *data)
{
	data->n.img = mlx_xpm_file_to_image(data->mlx,
			data->n.path, &data->n.w, &data->n.h);
	if (!data->n.img)
		return (printf("North texture path is wrong!\n"));
	data->s.img = mlx_xpm_file_to_image(data->mlx,
			data->s.path, &data->s.w, &data->s.h);
	if (!data->s.img)
		return (printf("South texture path is wrong!"));
	data->w.img = mlx_xpm_file_to_image(data->mlx,
			data->w.path, &data->w.w, &data->w.h);
	if (!data->w.img)
		return (printf("West texture path is wrong!"));
	data->e.img = mlx_xpm_file_to_image(data->mlx,
			data->e.path, &data->e.w, &data->e.h);
	if (!data->e.img)
		return (printf("East texture path is wrong!"));
	data->door.img = mlx_xpm_file_to_image(data->mlx,
			"textures/poly.xpm", &data->door.w, &data->door.h);
	return (0);
}

void	initialize_animation(t_data *data)
{
	int	i;

	data->frames[1].path = "textures/AnyConv.com__Crow-2.png.xpm";
	data->frames[2].path = "textures/AnyConv.com__Crow-3.png.xpm";
	data->frames[3].path = "textures/AnyConv.com__Crow-4.png.xpm";
	data->frames[4].path = "textures/AnyConv.com__Crow-5.png.xpm";
	data->frames[5].path = "textures/AnyConv.com__Crow-6.png.xpm";
	data->frames[6].path = "textures/AnyConv.com__Crow-7.png.xpm";
	data->frames[7].path = "textures/AnyConv.com__Crow-8.png.xpm";
	data->frames[8].path = "textures/AnyConv.com__Crow-9.png.xpm";
	data->frames[9].path = "textures/AnyConv.com__Crow-10.png.xpm";
	data->frames[10].path = "textures/AnyConv.com__Crow-11.png.xpm";
	data->frames[11].path = "textures/AnyConv.com__Crow-12.png.xpm";
	data->frames[12].path = "textures/AnyConv.com__Crow-13.png.xpm";
	data->frames[13].path = "textures/AnyConv.com__Crow-14.png.xpm";
	data->frames[14].path = "textures/AnyConv.com__Crow-15.png.xpm";
	i = 1;
	while (i <= 14)
	{
		data->frames[i].img = mlx_xpm_file_to_image(data->mlx,
				data->frames[i].path, &data->frames[i].w, &data->frames[i].h);
		i++;
	}
	animations_addr(data);
}

void	animations_addr(t_data *data)
{
	int	i;

	i = 1;
	while (i <= 14)
	{
		data->frames[i].addr = mlx_get_data_addr(data->frames[i].img,
				&data->frames[i].bits_per_pixel, &data->frames[i].size_line,
				&data->frames[i].endian);
		i++;
	}
}

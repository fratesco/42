/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:23:25 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/15 10:58:23 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_destroyer(t_data *data, void *img)
{
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
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}

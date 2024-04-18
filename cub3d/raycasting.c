/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:56:44 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/18 17:37:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->res_w)
	{
		data->player->camera_x = 2 * (i / (double)data->res_w) - 1;
		data->player->ray_dir_x = data->player->direct_x
			+ (data->player->plane_x * data->player->camera_x);
		data->player->ray_dir_y = data->player->direct_y
			+ (data->player->plane_y * data->player->camera_x);
		
		i++;
	}
}
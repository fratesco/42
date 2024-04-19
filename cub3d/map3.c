/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:17:33 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/19 12:10:59 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_direction(t_data *data)
{
	if (data->player->direction == 'N')
	{
		data->ray.direct_x = 0;
		data->ray.direct_y = 1;
		data->ray.plane_x = 0.66;
	}
	if (data->player->direction == 'W')
	{
		data->ray.direct_x = -1;
		data->ray.direct_y = 0;
		data->ray.plane_y = -0.66;
	}
	if (data->player->direction == 'E')
	{
		data->ray.direct_x = 1;
		data->ray.direct_y = 0;
		data->ray.plane_y = 0.66;
	}
	if (data->player->direction == 'S')
	{
		data->ray.direct_x = 0;
		data->ray.direct_y = -1;
		data->ray.plane_x = -0.66;
	}
}

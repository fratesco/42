/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:17:33 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/18 18:02:54 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_direction(t_data *data)
{
	if (data->player->direction == 'N')
	{
		data->player->direct_x = 0;
		data->player->direct_y = 1;
		data->player->plane_x = 0.66;
	}
	if (data->player->direction == 'W')
	{
		data->player->direct_x = -1;
		data->player->direct_y = 0;
		data->player->plane_y = -0.66;
	}
	if (data->player->direction == 'E')
	{
		data->player->direct_x = 1;
		data->player->direct_y = 0;
		data->player->plane_y = 0.66;
	}
	if (data->player->direction == 'S')
	{
		data->player->direct_x = 0;
		data->player->direct_y = -1;
		data->player->plane_x = -0.66;
	}
}

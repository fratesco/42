/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:38:13 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/27 18:24:22 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_forward(t_data *data)
{
    if (data->map[(int)floor(data->player->x + 0.1
        * data->ray.direct_x) - 1][(int)floor(data->player->y //check non funziona
        + 0.1 * data->ray.direct_y) - 1] != '1')
    {
        printf("%f %f %c\n", data->player->x, data->player->y, data->map[(int)floor(data->player->x + 0.1
        * data->ray.direct_x) - 1][(int)floor(data->player->y //check non funziona
        + 0.1 * data->ray.direct_y) - 1]);
        data->player->y += data->ray.direct_y * 0.1;
        data->player->x += data->ray.direct_x * 0.1;
    }
}

void    move_backwards(t_data *data)
{
    data->player->y -= 0.1;
}

void    move_right(t_data *data)
{
    data->player->x += 0.1;
}

void    move_left(t_data *data)
{
    data->player->x -= 0.1;
}
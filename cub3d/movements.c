/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:38:13 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/27 17:56:28 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_forward(t_data *data)
{
    data->player->y += 0.1;
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
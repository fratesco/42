/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:33:01 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/27 18:09:30 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keys_control_released(int kc, t_data *data)
{
    if (kc == 100) /*&& data->dead == FALSE */
		data->player->m_r = 0;
	if (kc == 97)/*&& data->dead == FALSE*/
		data->player->m_l = 0;
	if (kc == 115) /*&& data->dead == FALSE*/
		data->player->m_b = 0;
	if (kc == 119) /*&& data->dead == FALSE*/
		data->player->m_f = 0;
		return(0);
}

int	keys_control_movements(int kc, t_data *data)
{
    if (kc == 100) /*&& data->dead == FALSE */
	{
		data->player->m_r = 1;
		move_right(data);
	}
	if (kc == 97)/*&& data->dead == FALSE*/
	{
		data->player->m_l = 1;
		move_left(data);
	}
	if (kc == 115) /*&& data->dead == FALSE*/
	{
		data->player->m_b = 1;
		move_backwards(data);
	}
	if (kc == 119) /*&& data->dead == FALSE*/
	{
		data->player->m_f = 1;
		move_forward(data);
	}
	if (kc == 65307)
		close_game(data);
		return(0);
}

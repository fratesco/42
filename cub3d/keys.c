/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:33:01 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/28 23:08:10 by fratesco         ###   ########.fr       */
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
	if (kc == 65361)
		data->player->r_r = 0;
	if (kc == 65363)
		data->player->r_l = 0;
		return(0);
}

int	keys_control_movements(int kc, t_data *data)
{
    if (kc == 100) /*&& data->dead == FALSE */
		data->player->m_r = 1;
	if (kc == 97)/*&& data->dead == FALSE*/
		data->player->m_l = 1;
	if (kc == 115) /*&& data->dead == FALSE*/
		data->player->m_b = 1;
	if (kc == 119) /*&& data->dead == FALSE*/
		data->player->m_f = 1;
	if (kc == 65361)
		data->player->r_r = 1;
	if (kc == 65363)
		data->player->r_l = 1;
	if (kc == 65307)
		close_game(data);
	return(0);
}

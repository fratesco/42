/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moovementste.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:33:01 by srapuano          #+#    #+#             */
/*   Updated: 2024/04/09 14:52:27 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keys_controls(int kc, t_data *data)
{
	if (kc == 53 || kc == 2 || kc == 0 || kc == 1 || kc == 13
		|| kc == 15)
	{
		if (kc == 53)
			close_game(&data);
		keys_movements(kc, &data);
		mlx_clear_window(data->mlx, data->window);
		print_map(&data);
	}
	return (0);
}

void	keys_control_movements(int kc, t_data *data)
{
    if (kc == 2) /*&& data->dead == FALSE */
		move_right(&data);
	if (kc == 0)/*&& data->dead == FALSE*/
		move_left(&data);
	if (kc == 1) /*&& data->dead == FALSE*/
		move_down(&data);
	if (kc == 13) /*&& data->dead == FALSE*/
		move_up(&data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:11:13 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/19 11:50:31 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_check(t_data *data, int start, int i, char *str)
{
	int	j;

	if (start + i - 1 < 0)
		return (1);
	j = ft_strlen(str);
	if (j < start + i + 1)
		return (1);
	if ((str[start + i - 1] != ' ' && str[start + i - 1] != '1')
		|| (str[start + i + 1] != ' ' && str[start + i + 1] != '1'))
		return (1);
	if (data->list == NULL)
		data->list = ft_lstnew(start + i);
	else
		ft_lstadd_back(&data->list, ft_lstnew(start + i));
	return (0);
}

int	check_lines(char *str, int start, int raw, t_data *data)
{
	int	i;

	i = 0;
// bisogna controllare anche che se le dimensioni delle righte non coincidono, allora i caratteri di 'troppo'
//delle righe più lunghe siano tutti '1'
	if (data->list)
		if (check_list(data, str, 0) || list_free(data))
			return (1);
	while (str && str[start + i])
	{
		if ((raw == 0 || i == 0) && (str[start + i] != '1' && str[start + i] != ' '))
			return (1);
		if (str[start + i] == ' ')
		{
			if (new_check(data, start, i, str))
				return (1);
		}
		else if (str[start + i] != 'N' && str[start + i] != 'W'
			&& str[start + i] != 'E' && str[start + i] != 'S'
			&& str[start + i] != '0' && str[start + i] != '1')
			return (1);
		i++;
	}
	if (str && (str[start + i - 1] != '1' || str[start] == 0))
		return (1);
	return (0);
}

int	check_list(t_data *data, char *str, int len)
{
	if (!data->list)
		return (0);
	if (data->map_height >= 2)
	{	
		len = ft_strlen(data->map[data->map_height - 2]);
		if ((int)data->list->content > len)
			return (1);
		if (data->map[data->map_height - 2][(int)data->list->content] != '1'
			&& data->map[data->map_height - 2][(int)data->list->content] != ' ')
			return (1);
	}
	len = ft_strlen(str);
	if ((int)data->list->content > len)
		return (1);
	if (str[data->list->content] != '1' && str[data->list->content] != ' ')
		return (1);
	if (data->list->next)
	{
		data->save_list = data->list;
		data->list = data->list->next;
		if (check_list(data, str, 0))
			return (1);
	}
	return (0);
}

int	last_check(t_data *data, int i)
{
	if (check_lines(data->map[data->map_height - 1], i, 0, data))
		return (1);
	if (check_list(data, data->map[data->map_height - 1], 0) || list_free(data))
		return (1);
	return (0);
}

int	find_player(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
					&& data->player->found == 0)
			{
				data->player->x = i + 0.5;
				data->player->y = j + 0.5;
				data->player->found = 1;
				data->player->direction = data->map[i][j];
			}
			else if ((data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
					&& data->player->found == 1)
				return (printf("Too many players in the map!\n"));
			i++;
		}
	}
	find_direction(data);
	return (0);
}

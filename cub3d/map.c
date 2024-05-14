/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:03 by fgolino           #+#    #+#             */
/*   Updated: 2024/05/14 12:45:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	spaces_skipper(char *str, int start)
{
	int	i;

	i = start;
	while (str && str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f' ))
		i++;
	return (i);
}

int	comparer(char *tmp, t_data *data, int i)
{
	if (!ft_strncmp(&tmp[i], "NO", 2) && !data->n.path)
		data->n.path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "WE", 2) && !data->w.path)
		data->w.path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "EA", 2) && !data->e.path)
		data->e.path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "SO", 2) && !data->s.path)
		data->s.path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "F", 1))
		data->floor.color = string_to_rgb(&tmp[spaces_skipper(tmp, i + 2)],
				0, 0, 3);
	else if (!ft_strncmp(&tmp[i], "C", 1))
		data->ceiling.color = string_to_rgb(&tmp[spaces_skipper(tmp, i + 2)],
				0, 0, 3);
	else
	{
		printf("Invalid format for the .ber file\n");
		free(tmp);
		return (0);
	}
	free(tmp);
	if (data->floor.color == -1 || data->ceiling.color == -1)
		return (0);
	return (1);
}

int	string_to_rgb(char *str, int i, int j, int counter)
{
	if (color_checker(str, 0))
		return (-1);
	while (counter--)
	{
		i = i << 8;
		j = ft_atoi(str);
		if (j < 0, j > 255)
		{
			printf ("RGB numbers must be 0 <= n <= 255\n");
			return (-1);
		}
		str = ft_strchr(str, ',');
		if (!str && (counter != 0))
		{
			printf("Invalid RGB format\n");
			return (-1);
		}
		i += j;
		str++;
	}
	return (i);
}

int	checker(t_data *data, int i, int j)
{
	char	*tmp;

	while (j < 6)
	{
		tmp = get_next_line(data->ber_fd);
		if (tmp == (void *)1)
		{
			printf("Not enough elements in the .ber file\n");
			return (1);
		}
		if (!tmp)
			continue ;
		i = spaces_skipper(tmp, 0);
		if (i == ft_strlen(tmp))
		{
			free(tmp);
			continue ;
		}
		if (comparer(tmp, data, i))
			j++;
		else
			return (1);
	}
	return (0);
}

int	check_map(t_data *data, int i, char *tmp, int cond)
{
	while (cond)
	{
		tmp = get_next_line(data->ber_fd);
		if (tmp == (void *)1)
			break ;
		else if ((!tmp || !tmp[0]) && data->map_height == 0)
		{
			free (tmp);
			continue ;
		}
		data->p = spaces_skipper(tmp, 0);
		if (data->map_height == 0)
			if (tmp[data->p] && check_lin(tmp, 0, 0, data))
				cond = 0;
		if (tmp[data->p] && cond && check_lin(tmp, 0, 1, data) || !tmp[data->p])
			cond = 0;
		data->map = matrix_crusher(data->map, &tmp[0], 0);
		free(tmp);
		data->map_height++;
	}
	if (cond && last_check(data, i))
		cond = 0;
	if (!cond)
		printf("Invalid map\n");
	return (cond);
}

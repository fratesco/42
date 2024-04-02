/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:03 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/02 17:42:53 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	spaces_skipper(char *str, int start)
{
	int	i;

	i = start;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
		i++;
	return (i);
}

int	comparer(char *tmp, t_data *data, int i)
{
	if (!ft_strncmp(&tmp[i], "NO", 2))
		data->n_path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "WE", 2))
		data->w_path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "EA", 2))
		data->e_path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "SO", 2))
		data->s_path = ft_strdup(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "F", 1))
		data->floor_color = string_to_rgb(&tmp[spaces_skipper(tmp, i + 2)],
				0, 0, 3);
	else if (!ft_strncmp(&tmp[i], "C", 1))
		data->ceiling_color = string_to_rgb(&tmp[spaces_skipper(tmp, i + 2)],
				0, 0, 3);
	else
	{
		printf("Invalid format for the .ber file\n");
		free(tmp);
		return (0);
	}
	free(tmp);
	if (data->floor_color == -1 || data->ceiling_color == -1)
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
			break ;
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
			break ;
	}
	get_next_line(-1);
}

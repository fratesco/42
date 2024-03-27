/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:03 by fgolino           #+#    #+#             */
/*   Updated: 2024/03/27 12:50:29 by fgolino          ###   ########.fr       */
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
		data->floor_color = string_to_rgb(&tmp[spaces_skipper(tmp, i + 2)]);
	else if (!ft_strncmp(&tmp[i], "C", 1))
		data->ceiling_color = string_to_rgb(&tmp[spaces_skipper(tmp, i + 2)]);
	else
	{
		printf("Invalid format for the .ber file\n");
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	string_to_rgb(char *str)
{
	return (0);
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

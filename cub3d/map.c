/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:03 by fgolino           #+#    #+#             */
/*   Updated: 2024/03/26 18:09:33 by fgolino          ###   ########.fr       */
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
	else if (!ft_strncmp(&tmp[i], "W£", 2))
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
		
		return (0);
	}
	free(tmp);
	return (1);
}

int	string_to_rgb(char *str)
{
	return 0;
}

int	checker(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (j < 6)
	{
		tmp = get_next_line(data->ber_fd);
		if (!tmp)
		{
			//capire come fare a distinguere quando il file è tutto vuoto e quando il file è contiene delle righe vuote tra gli elementi
			printf("Not enough elements in the .ber file\n");
			break ;
		}
		i = spaces_skipper(tmp, 0);
		if (i == ft_strlen(tmp))
		{
			free(tmp);
			continue ;
		}
		if (comparer(tmp, data, i))
			j++;
		else
		{
			printf("Invalid format for the .ber file\n");
			free(tmp);
			break ;
		}
	}
}
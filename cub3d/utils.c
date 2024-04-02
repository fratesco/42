/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:28:23 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/02 17:48:48 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix != NULL && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix != NULL)
	{
		if (matrix[i])
			free(matrix[i]);
		free(matrix);
	}
	return ;
}

int	color_checker(char *str, int i)
{
	while (str && str[i])
	{
		if (((str[i] < '0' && str[i] != ',') || str[i] > '9')
			&& (str[i] != ' ' || str[i] != '\t' || str[i] != '\v'))
		{
			printf("Only numbers are accepted as RGB values\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	freerer(t_data *data)
{
	if (data->n_path)
		free(data->n_path);
	if (data->s_path)
		free(data->s_path);
	if (data->w_path)
		free(data->w_path);
	if (data->e_path)
		free(data->e_path);
	free_matrix(data->map);
}
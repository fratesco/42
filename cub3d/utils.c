/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:28:23 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/12 13:11:00 by fgolino          ###   ########.fr       */
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
	if (data->list)
		list_free(data);
	if (data->player)
		free(data->player);
	free_matrix(data->map);
}

char	**matrix_crusher(char **matrix, char *str, int i)
{
	char	**nmatrix;

	while (matrix && matrix[i])
		i++;
	nmatrix = (char **)malloc(sizeof(char *) * (i + 2));
	if (!nmatrix)
	{
		free (nmatrix);
		return (NULL);
	}
	i = -1;
	while (matrix && matrix[++i])
		nmatrix[i] = ft_strdup(matrix[i]);
	if (str)
	{
		if (!matrix)
			i = 0;
		nmatrix[i] = ft_strdup(str);
		nmatrix[i + 1] = NULL;
	}
	else
		nmatrix[i] = NULL;
	free_matrix(matrix);
	return (nmatrix);
}

int	list_free(t_data *data)
{
	t_list	*tmp;

	if (data->save_list)
		data->list = data->save_list;
	while (data->list)
	{
		tmp = data->list;
		data->list = data->list->next;
		free(tmp);
	}
	data->save_list = NULL;
	return (0);
}

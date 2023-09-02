/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:38:35 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 13:48:36 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix != NULL && matrix[i])
		free(matrix[i++]);
	if (matrix != NULL)
		free(matrix);
}

char	**get_path(char *path)
{
	return (ft_split(path, ':'));
}

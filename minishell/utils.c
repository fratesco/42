/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:38:35 by fgolino           #+#    #+#             */
/*   Updated: 2023/08/30 17:27:46 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info g_info;

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] && matrix != NULL)
		free(matrix[i++]);
	free(matrix);
}

char	**get_path(char *path)
{
	return (ft_split(path, ':'));
}

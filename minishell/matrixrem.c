/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:01:45 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/13 11:28:05 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

char	**matrix_remover(char **matrix, int ind)
{
	char	**nmatrix;
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
		i++;
	nmatrix = (char **)malloc(sizeof(char *) * (i));
	if (!nmatrix)
	{
		free (nmatrix);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (matrix[++i])
	{
		if (i == ind)
			i++;
		nmatrix[j] = ft_strdup(matrix[i]);
		j++;
	}
	nmatrix[j] = NULL;
	return (nmatrix);
}

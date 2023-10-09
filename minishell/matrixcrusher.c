/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixcrusher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:56:14 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/09 16:14:53 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **matrix_crusher(char **matrix, char *str)
{
	char **nmatrix;
	int i;

	i = 0;
	while(matrix[i])
	{
		i++;
	}
	i++;
	nmatrix = (char **)malloc(sizeof(char *) * (i + 1));
	if (!nmatrix)
	{
		free (nmatrix);
		return (NULL);
	}
	i = -1;
	while (matrix[++i])
	{
		nmatrix[i] = ft_strdup(matrix[i]);
	}
	nmatrix[i] = ft_strdup(str);
	nmatrix[i + 1] = NULL;
	return (nmatrix);
}

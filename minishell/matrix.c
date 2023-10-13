/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:56:14 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/13 11:33:42 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

char	**matrix_crusher(char **matrix, char *str)
{
	char	**nmatrix;
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	nmatrix = (char **)malloc(sizeof(char *) * (i + 2));
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
	if (str)
	{
		nmatrix[i] = ft_strdup(str);
		nmatrix[i + 1] = NULL;
	}
	else
		nmatrix[i] = NULL;
	return (nmatrix);
}

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

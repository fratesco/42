/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:56:14 by srapuano          #+#    #+#             */
/*   Updated: 2023/11/08 17:12:03 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

char	**matrix_crusher(char **matrix, char *str)
{
	char	**nmatrix;
	int		i;

	i = 0;
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
	nmatrix = (char **)malloc(sizeof(char *) * (i--));
	if (!nmatrix)
	{
		free (nmatrix);
		return (NULL);
	}
	j = i - 1;
	nmatrix[j + 1] = NULL;
	while (i >= 0)
	{
		if (i == ind)
			i--;
		nmatrix[j] = ft_strdup(matrix[i]);
		i--;
		j--;
	}
	return (nmatrix);
}

void	matrix_cleaner(char **m, int i)
{
    int j;
    int k;
	char **tmp;

    j = -1;
    while (++j < i)
    {
        if (m[j] == NULL || ((m[j][0] == '<'
			|| m[j][0] == '>') && m[j][1] == '\0'))
		{
            tmp = matrix_remover(m, j);
			free(m);
			&m = tmp;
			free(tmp);
		}
    }
}
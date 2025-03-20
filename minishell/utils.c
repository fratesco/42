/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:38:35 by fgolino           #+#    #+#             */
/*   Updated: 2025/03/20 21:18:51 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

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

void	free_stuff(t_info *info, int flag)
{
	if (flag == 1)
	{
		free_matrix(info->instr_token);
		info->num_arg = 0;
		info->instr_token = NULL;
		info->current_arg = 1;
		if (info->use_redirect)
		{
			free(info->use_redirect);
			info->use_redirect = 0;
		}
		info->status_export_flag = 0;
	}
	else
	{
		free(info->current_path);
		free(info->user);
		free_matrix(info->global_path);
		free_matrix(info->instr_token);
		free_matrix(info->environment);
		rl_clear_history();
	}
}

char	*triple_join(char *start, char *middle, char *end)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(start, middle);
	tmp2 = ft_strjoin(tmp, end);
	free(tmp);
	return (tmp2);
}

char	*get_global(char **matrix, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (matrix[++i])
	{
		j = 0;
		while (matrix[i][j] != '=')
			j++;
		if (ft_strncmp(matrix[i], str, j) == 0)
		{
			//tmp = ft_strdup(&matrix[i][j + 1]);
			return (&matrix[i][j + 1]);
		}
	}
	return (NULL);
}

void	count_redirect(t_info *info, int i, int j, int count)
{
	int	flag;

	count_allocate(info);
	flag = 1;
	while (info->instr_token && info->instr_token[i])
	{
		j = 0;
		while (info->instr_token[i][j])
		{
			if (info->instr_token[i][j] == '"' ||
				info->instr_token[i][j] == '\'')
				flag *= -1;
			if (info->instr_token[i][j] == '>' ||
				info->instr_token[i][j] == '<')
			{
				if (flag == -1)
					info->use_redirect[count++] = 0;
				else
					info->use_redirect[count++] = 1;
			}
			j++;
		}
		i++;
	}
	info->use_redirect[count] = 10;
}

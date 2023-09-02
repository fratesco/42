/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:38:35 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 18:33:40 by fgolino          ###   ########.fr       */
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

char	**pipe_finder(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_info.instr_token && g_info.instr_token[i])
	{
		j = 0;
		while (g_info.instr_token[i][j])
		{
			if ()
		}
	}
}

void	free_stuff(void)
{
	free(g_info.user);
	free(g_info.current_path);
	free_matrix(g_info.global_path);
	free_matrix(g_info.instr_token);
	rl_clear_history();
}

int	redirector(void)
{
	int	i;

	i = 0;
	while (g_info.instr_token[i] && g_info.temp_stdout == 0)
	{
		if (ft_strncmp(">", g_info.instr_token[i], 1) == 0)
		{
			if (i + 1 == g_info.instr_len)
			{
				printf("Syntax error\n");
				return (-1);
			}
		}
		i++;
	}
}

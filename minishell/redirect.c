/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:06:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/16 14:09:00 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	redirector(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = 0;
	while (info->instr_token[++i])
	{
		while (info->instr_token[i][j])
		{
			if (info->instr_token[i][j] == '"' ||
			info->instr_token[i][j] == '\'')
			{
				c = info->instr_token[i][j];
				while (info->instr_token[i][j] != c)
					j++;
			}
			if (info->instr_token[i][j] == '>')
				output_router(info, i, j);
			else if (info->instr_token[i][j] == '<')
				input_router(info, i, j);
			j++;
		}	
	}	
	return (0);
}

void	output_router(t_info *info, int row, int col)
{
	//if (info->instr_token[row][col + 1] == '>')
	// qui fai open in append mode
	
}	

void	input_router(t_info *info, int row, int col)
{
	if (info->instr_token[row][col + 1] == '<')
		return ;// qui deve partire tutta un'altra funzione che si occupa di prendere l'input da stdin fino a che non viene scrittol il delimitatore
}

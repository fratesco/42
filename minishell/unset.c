/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:49:40 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/13 13:34:32 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void ft_unset(t_info *info, int arg)
{
	int	i;
	int	j;
	char **tmp;

	i = -1;
	while (info->environment[++i])
	{
		j = 0;
		while (info->environment[i][j] != '=')
			j++;
		if (ft_strncmp(info->environment[i], info->instr_token[arg], j) == 0)
		{
				
				tmp = matrix_remover(info->environment, i);
				break ;
		}
	}
	free_matrix(info->environment);
	info->environment = tmp;
	if ((arg) < info->num_arg - 1)
		ft_unset(info, (arg + 1));
}

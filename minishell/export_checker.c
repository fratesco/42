/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:17 by srapuano          #+#    #+#             */
/*   Updated: 2023/11/07 15:09:45 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

extern int	g_signal;

int	export_checker(t_info *info, char *str)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	index = (int)(ft_strchr(str, '=') - str);
	while (info->environment[++i])
	{
		j = 0;
		while (info->environment[i][j] && info->environment[i][j] != '=')
			j++;
		if (index == j)
		{
			if (ft_strncmp(info->environment[i], str, j) == 0)
			{
				if (str[j] != '=')
					return (1);
				free(info->environment[i]);
				info->environment[i] = ft_strdup(str);
				return (1);
			}
		}
	}

	return (0);
}

void	export_no_arg(t_info *info, int i, int j)
{
	int		t;
	char	**tmp;
	char	*str;

	tmp = matrix_crusher(info->environment, NULL);
	while (tmp[++i])
	{
		t = i + 1;
		j = 0;
		while (tmp[i][j] && tmp[i][j] != '=' && tmp[t])
			j++;
		while (tmp[t])
		{
			if (ft_strncmp(tmp[i], tmp[t], j) >= 0)
			{
				str = tmp[i];
				tmp[i] = tmp[t];
				tmp[t] = str;
			}
			t++;
		}
	}
	p_export_no_arg(tmp);
	free(tmp);
}

void	p_export_no_arg(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = 0;
		while (tmp[i][j] && tmp[i][j] != '=')
			j++;
		if (tmp[i][j] == 0)
			printf("declare -x %s\n", tmp[i]);
		else
			printf("declare -x %.*s=\"%s\"\n", j, tmp[i], &tmp[i][j + 1]);
	}
}

void	export_exec(info, char **tmp, int arg)
{
		tmp = matrix_crusher(info->environment, info->instr_token[arg]);
		free_matrix(info->environment);
		info->environment = tmp;
}

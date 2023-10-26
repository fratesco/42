/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:17 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/26 12:47:23 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

extern int	g_signal;

int	export_checker(t_info *info, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (info->environment[++i])
	{
		j = 0;
		while (info->environment[i][j] && info->environment[i][j] != '=')
			j++;
		if (ft_strncmp(info->environment[i], str, j) == 0)
		{
			if (str[j] != '=')
				return (1);
			free(info->environment[i]);
			info->environment[i] = ft_strdup(str);
			return (1);
		}
	}
	return (0);
}

void export_no_arg(t_info *info, int i, int j)
{
	int t;
	char **tmp;
	char *str;
	
	tmp = matrix_crusher(info->environment, NULL);
	while(tmp[++i])
	{
		if (tmp[i + 1] == NULL)
			break ;
		t = i + 1;
		j = 0;
		while(tmp[i][j] && tmp[i][j] != '=')
			j++;
		while(tmp[t])
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
}

void p_export_no_arg(char **tmp)
{
	int i;
	int j;
	
	i = -1;
	while (tmp[++i])
	{
		j = 0;
		while(tmp[i][j] && tmp[i][j] != '=')
			j++;
		if (tmp[i][j] == 0)
			printf("declare -x %s\n", tmp[i]);
		else
		{
			j += 1;
			printf("declare -x %.*s\"%s\"\n", j, tmp[i], &tmp[i][j + 1]);
		}
	}
}
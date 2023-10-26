/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:17 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/26 11:21:48 by fgolino          ###   ########.fr       */
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
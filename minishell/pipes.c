/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:27:13 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/05 12:41:58 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pip_index(t_info *info)
{
	int	i;
	char t;

	i = 0;
	info->num_pipe = 0;
	while (info->instruction[i++])
	{
		while (info->instruction[i] != '|' && info->instruction[i] != '\0')
		{
			if (info->instruction[i] == '\'' || info->instruction[i] == '"')
			{
				t = info->instruction[i++];
				while (info->instruction[i] != '\0'
					&& info->instruction[i] != t)
					i++;
			}
			i++;
		}
		if (info->instruction[i] == '|')
		{
			info->num_pipe = 1;
			break ;
		}
	}
	info->pos_pipe = i;
}

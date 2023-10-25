/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:34:18 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/25 16:20:02 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	count_allocate(t_info *info)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (info->instr_token && info->instr_token[i])
	{
		j = 0;
		while (info->instr_token[i][j])
		{
			if (info->instr_token[i][j] == '>' ||
				info->instr_token[i][j] == '<')
				count++;
			j++;
		}
		i++;
	}
	info->use_redirect = (int *)malloc(sizeof(int) * count);
}
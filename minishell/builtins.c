/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/28 13:04:18 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_handler(t_info *info)
{
	if (redirector(info) == -1)
		return ;
	printf("%s\n", info->current_path);
}

void	echo_handler(t_info *info)
{
	info->current_arg = 1;
	while (info->instr_token[info->current_arg])
	{
		printf("%s ", info->instr_token[info->current_arg]);
		info->current_arg++;
	}
	if (info->instr_token[1]
		&& ft_strncmp(info->instr_token[1], "-n", 2) != 0)
		printf("\n");
	return ;
}

void	cd_handler(t_info *info)
{
	
	return ;
}

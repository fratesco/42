/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/26 18:59:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	pwd_handler(void)
{
	if (redirector() == -1)
		return ;
	printf("%s\n", g_info.current_path);
}

void	echo_handler(void)
{
	g_info.current_arg = 1;
	while (g_info.instr_token[g_info.current_arg])
	{
		printf("%s ", g_info.instr_token[g_info.current_arg]);
		g_info.current_arg++;
	}
	if (g_info.instr_token[1]
		&& ft_strncmp(g_info.instr_token[1], "-n", 2) != 0)
		printf("\n");
	return ;
}

void	cd_handler(void)
{
	
	return ;
}

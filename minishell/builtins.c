/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/29 18:41:52 by fgolino          ###   ########.fr       */
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
	int		i;
	char	*tmp;

	if (info->num_arg < 2)
		return ((void)chdir(getenv("HOME")));
	if (info->num_arg > 2)
		printf("cd: too many arguments\n");
	if (chdir(info->instr_token[1]) != 0)
	{
		i = 0;
		while (info->global_path[i])
		{
			tmp = triple_join(info->global_path[i], "/", info->instr_token[1]);
			if (!chdir(tmp))
			{
				free(tmp);
				break ;
			}
			else
				free(tmp);
			i++;
		}
	}
	free(info->current_path);
	info->current_path = getcwd(NULL, 0);
	return ;
}

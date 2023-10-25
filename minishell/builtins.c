/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/25 16:01:23 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	pwd_handler(t_info *info)
{
	printf("%s\n", info->current_path);
	info->exit_status = 0;
}

void	echo_handler(t_info *info)
{
	info->current_arg = 1;
	while (info->instr_token[info->current_arg])
	{
		printf("%s", info->instr_token[info->current_arg]);
		if (info->instr_token[info->current_arg][0] != 0)
			printf(" ");
		info->current_arg++;
	}
	if (info->instr_token[1]
		&& ft_strncmp(info->instr_token[1], "-n", 2) != 0)
		printf("\n");
	info->exit_status = 0;
	return ;
}

void	cd_handler(t_info *info)
{
	if (info->num_arg < 2)
		chdir(getenv("HOME"));
	if (info->num_arg > 2)
	{
		info->exit_status = 1;
		printf("cd: too many arguments\n");
	}
	if (info->num_arg == 2 && chdir(info->instr_token[1]) != 0)
	{
		info->exit_status = 1;
		if (errno == EACCES)
			printf ("cd : %s : Permission denied\n", info->instr_token[info->current_arg]);
		else if (errno == ENOTDIR)
			printf ("cd : %s : Not a directory\n", info->instr_token[info->current_arg]);
		else if (cd_loop(info))
			printf("cd : %s : %s\n", info->instr_token[info->current_arg], strerror(errno));
		else
			info->exit_status = 0;
	}
	else if (info->num_arg == 2)
		info->exit_status = 0;
	free(info->current_path);
	info->current_path = getcwd(NULL, 0);
}

void	export_handler(t_info *info, int arg)
{
	int		i;
	char	**tmp;

	if (info->num_arg == 1)
	{
		info->exit_status = 0;
		return ;
	}
	if (token_checker(info, arg))
	{
		printf("export: '%s' : not a valid identifier\n",
			info->instr_token[arg]);
		info->exit_status = 1;
		return ;
	}
	tmp = matrix_crusher(info->environment, info->instr_token[arg]);
	free_matrix(info->environment);
	info->environment = tmp;
	if ((arg) < info->num_arg - 1)
		export_handler(info, (arg + 1));
	info->exit_status = 0;
}

void	env_handler(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->environment[i])
	{
		j = 0;
		while (info->environment[i][j])
		{
			if (info->environment[i][j] == '=')
			{
				printf("%s\n", info->environment[i]);
				info->exit_status = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	info->exit_status = 0;
}

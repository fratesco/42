/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/12/12 12:28:41 by fgolino          ###   ########.fr       */
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
	if (info->instr_token[1]
		&& ft_strncmp(info->instr_token[1], "-n", 2) == 0)
			info->current_arg = 2;
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
	info->exit_status = 1;
	if (info->num_arg < 2)
		chdir(get_global(info->environment, "HOME"));
	if (info->num_arg > 2)
		printf("cd: too many arguments\n");
	if (info->num_arg == 2 && (chdir(info->instr_token[1]) != 0))
	{
		if (errno == EACCES)
			printf ("cd : %s : Permission denied1\n",
				info->instr_token[info->current_arg]);
		else if (errno == ENOTDIR)
			printf ("cd : %s : Not a directory\n",
				info->instr_token[info->current_arg]);
		else if (cd_loop(info, -1))
			printf("cd : %s : %s\n",
				info->instr_token[info->current_arg], strerror(errno));
	}
	else if (info->num_arg <= 2)
		info->exit_status = 0;
	free(info->current_path);
	info->current_path = getcwd(NULL, 0);
}

void	export_handler(t_info *info, int arg, int f, int ff)
{
	char	**tmp;

	if (info->num_arg == 1)
	{
		export_no_arg(info, -1, 0);
		info->exit_status = 0;
		return ;
	}
	if (token_checker(info, arg))
	{
		printf("export: '%s' : not a valid identifier\n",
			info->instr_token[arg]);
		info->status_export_flag = 1;
		ff = 1;
	}
	if (ff != 1 && !export_checker(info, info->instr_token[arg]))
		export_exec(info, tmp, arg);
	if ((arg) < info->num_arg - 1)
		export_handler(info, (arg + 1), 0, 0);
	if (info->status_export_flag == 1)
		info->exit_status = 1;
	else
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:49:24 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/13 13:51:18 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	unset_handler(t_info *info, int arg)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	while (info->environment[++i])
	{
		j = 0;
		while (info->environment[i][j] != '=')
			j++;
		if (ft_strncmp(info->environment[i], info->instr_token[arg], j) == 0)
		{
			tmp = matrix_remover(info->environment, i);
			break ;
		}
	}
	free_matrix(info->environment);
	info->environment = tmp;
	if ((arg) < info->num_arg - 1)
		unset_handler(info, (arg + 1));
	info->exit_status = 0;
}

int	cd_loop(t_info *info)
{
	int		i;
	char	*tmp;

	i = -1;
	while (info->global_path[++i])
	{
		tmp = triple_join(info->global_path[i], "/", info->instr_token[1]);
		if (!chdir(tmp))
		{
			free(tmp);
			return (0);
		}
		else if (errno == EACCES || errno == ENOTDIR)
		{
			if (errno == EACCES)
				printf("cd : %s : Permission denied\n", tmp);
			else if (errno == ENOTDIR)
				printf ("cd : %s : Not a directory\n", info->instr_token[1]);
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

void	exit_handler(t_info *info)
{
	int	i;

	i = 0;
	while (info->instr_token[1][i])
	{
		if (info->instr_token[1][i] < 48 || info->instr_token[1][i] > 57)
		{
			printf("exit\n");
			printf("exit: %s: numeric argument required\n",
				info->instr_token[1]);
			free_stuff(info, 1);
			free_stuff(info, 0);
			exit(2);
		}
		i++;
	}
	i = ft_atoi(info->instr_token[1]);
	free_stuff(info, 1);
	free_stuff(info, 0);
	exit(i);
}

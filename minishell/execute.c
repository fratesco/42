/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:29:57 by fgolino           #+#    #+#             */
/*   Updated: 2024/01/22 15:00:41 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	found(t_info *info, char *path)
{
	DIR	*fd;

	if (!access(path, X_OK))
	{
		fd = opendir(path);
		if (fd == NULL && errno == ENOTDIR)
		{
			execve(path, info->instr_token, info->environment);
			exit(0);
		}
		else if (fd != NULL)
		{
			closedir(fd);
			printf("%s : Is a directory\n", path);
			exit(126);
		}
	}
	else
		printf("Permission denied\n");
	exit(126);
}

void	try_find_do(t_info *info, char *name, int i, int j)
{
	char	*tmp;

	if (!access(name, F_OK))
		found(info, name);
	else
	{
		tmp = get_global(info->environment, "PATH");
		free_matrix(info->global_path);
		info->global_path = 0;
		if (tmp)
			info->global_path = ft_split(tmp, ':');
		while (info->global_path && info->global_path[i])
		{
			tmp = triple_join(info->global_path[i++], "/", name);
			if (!access(tmp, F_OK))
			{
				found(info, tmp);
				free(tmp);
				break ;
			}
			free(tmp);
		}
		printf("%s: command not found\n", name);
		exit(127);
	}
}

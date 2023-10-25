/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:29:57 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/25 16:21:25 by fgolino          ###   ########.fr       */
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

void	try_find_do(t_info *info, char *name)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!access(name, F_OK))
		found(info, name);
	else
	{
		while (info->global_path[i])
		{
			tmp = triple_join(info->global_path[i], "/", name);
			if (!access(tmp, F_OK))
			{
				found(info, tmp);
				free(tmp);
				break ;
			}
			free(tmp);
			i++;
		}
		printf("%s: command not found\n", name);
		exit(127);
	}
}

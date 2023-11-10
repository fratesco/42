/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:27:13 by srapuano          #+#    #+#             */
/*   Updated: 2023/11/10 12:35:31 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pip_index(t_info *info)
{
	int		i;
	char	t;

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

void	tmp_file_creator(t_info *info, int action)
{
	static char	*directory;
	char		**matr;

	if (directory == 0)
		directory = ft_strjoin(info->current_path, "/ZZZ");
	if (action == 0)
		info->tmp_fd = open(directory, O_CREAT | O_WRONLY, 0666);
	else if (action == 1)
		info->tmp_fd = open(directory, O_RDONLY);
	else if (action == 2)
	{
		close(info->tmp_fd);
		info->tmp_fd = 0;
	}
	if (action == 3)
	{
		matr = (char **)malloc(sizeof(char *) * 3);
		matr[0] = ft_strdup("/usr/bin/rm");
		matr[1] = directory;
		matr[2] = 0;
		if (!fork)
			execve(matr[0], matr, info->environment); //puoi provare a usare lo stesso minishell per fare questa cosa aggiungendo manualmente un "rm ZZZ"
													  //dopo e farlo partire come se fosse dopo una pipe
		free_matrix(matr);
		directory = 0;
	}
}

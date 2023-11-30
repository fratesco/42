/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/30 13:22:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	start(t_info *info)
{
	char	**tokens;
	int		len;

	if (ft_strncmp(info->instruction, "", 1) == 0)
		return ;
	add_history(info->instruction);
	if (check_string(info->instruction))
		return ;
	pip_index(info);
	tokens = splitter(&info->instruction[info->instr_start], ' ',
			info->pos_pipe - info->instr_start, &len);
	info->instr_start = info->pos_pipe + 1;
	if (!tokens)
		return (free_matrix(tokens));
	info->instr_token = tokens;
	info->num_arg = len;
	count_redirect(info, 0, 0, 0);
	if (info->pipe_fd1[0] == 0 && info->num_pipe == 1)
	{
		pipe(info->pipe_fd1);
		if (!info->temp_stdout)
			info->temp_stdout = dup(STDOUT_FILENO);
		dup2(info->pipe_fd1[1], STDOUT_FILENO);
	}
	else if (info->pipe_fd1[1] == 0 && info->num_pipe == 1)
	{
		//printf("quiiii\n");
		pipe(info->pipe_fd2);
		if (!info->temp_stdout)
			info->temp_stdout = dup(STDOUT_FILENO);
		dup2(info->pipe_fd2[1], STDOUT_FILENO);
	}
}

void	analizer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	dollar_handler(info);
	polish_tokens(info);
	redirector(info);
	matrix_cleaner(&(info->instr_token), info->num_arg);
	i = ft_strlen(info->instr_token[0]);
	if (ft_strncmp(info->instr_token[0], "pwd", i) == 0)
		pwd_handler(info);
	else if (ft_strncmp(info->instr_token[0], "echo", i) == 0)
		echo_handler(info);
	else if (ft_strncmp(info->instr_token[0], "cd", i) == 0)
		cd_handler(info);
	else if (ft_strncmp(info->instr_token[0], "env", i) == 0)
		env_handler(info);
	else if (ft_strncmp(info->instr_token[0],
			"export", i) == 0)
		export_handler(info, info->current_arg, 0, 0);
	else if (ft_strncmp(info->instr_token[0], "unset", i) == 0)
		unset_handler(info, info->current_arg, -1);
	else if (ft_strncmp(info->instr_token[0], "exit", i) == 0)
		exit_handler(info);
	else
	{
		info->instr_pid = fork();
		if (!info->instr_pid)
		{
			signal_fork();
			try_find_do(info, info->instr_token[0]);
		}
		signal_avoid();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2024/01/22 15:04:43 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

void	initializer(t_info *info)
{
	info->total_instructions = 0;
	info->temp_stdout = 0;
	info->temp_stdin = 0;
	info->temp_in_fd = 0;
	info->temp_out_fd = 0;
	info->tmp_fd = 0;
	info->use_redirect = 0;
	info->instr_token = NULL;
	info->current_arg = 1;
	info->instr_pid = 0;
	info->received_signal = 0;
	info->exit_status = 0;
	info->is_error = 0;
	info->save_index = 0;
	info->str_error = 0;
	info->pipe_fd1[0] = 0;
	info->pipe_fd1[1] = 0;
	info->pipe_fd2[0] = 0;
	info->pipe_fd2[1] = 0;
}

void	get_environment(t_info *g_info, char **environment)
{
	char	*tmp;

	tmp = 0;
	g_info->environment = matrix_crusher(environment, NULL);
	tmp = get_global(g_info->environment, "PATH");
	if (tmp)
		g_info->global_path = ft_split(tmp, ':');
	if (tmp)
		free(tmp);
	tmp = get_global(g_info->environment, "USER");
	g_info->user = ft_strjoin(tmp, (":~"));
	free(tmp);
	signal_rewire();
	g_info->current_path = get_global(g_info->environment, "HOME");
	chdir(g_info->current_path);
	initializer(g_info);
}

void	executing(t_info *info)
{
	int	status;

	status = 0;
	info->num_pipe = 0;
	info->instr_pid = 0;
	info->num_arg = 0;
	start(info);
	if (info->num_arg != 0)
		clean_tokens(info);
	if (info->num_arg != 0 && info->is_error == 0)
		analizer(info, (int)ft_strlen(info->instr_token[0]), 0);
	if (info->instr_pid != 0)
	{
		wait(&(status));
		if (WIFEXITED(status))
			info->exit_status = WEXITSTATUS(status);
		signal_rewire();
		if (g_signal == SIGINT)
		{
			printf("\n");
			info->exit_status = 130;
		}
	}
	info->instr_pid = 0;
	g_signal = 0;
}

int	main(int argc, char	**argv, char **envp)
{
	t_info	info;

	if (argc > 1)
	{
		printf("Minishell takes no argument\n");
		exit(0);
	}
	get_environment(&info, envp);
	while (1)
	{
		info.instr_start = 0;
		info.num_pipe = 1;
		info.instruction = readline(info.user);
		if (info.instruction == NULL && info.instr_pid == 0)
			break ;
		while (info.num_pipe == 1)
		{
			executing(&info);
			reset_all(&info);
			free_stuff(&info, 1);
		}
		free(info.instruction);
	}
	free_stuff(&info, 0);
	return (0);
}

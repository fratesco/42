/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/26 18:09:16 by fgolino          ###   ########.fr       */
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
	tokens = splitter(info->instruction, ' ', info->pos_pipe, &len);
	if (!tokens)
		return (free_matrix(tokens));
	info->instr_token = tokens;
	info->num_arg = len;
	count_redirect(info, 0, 0, 0);
}

void	analizer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	dollar_handler(info);
	polish_tokens(info);
	redirector(info);
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
		export_handler(info, info->current_arg);
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
			exit (0);
		}
		signal_avoid();
	}
	if (info->temp_stdout)
	{
		close(info->temp_out_fd);
		dup2(info->temp_stdout, STDOUT_FILENO);
		info->temp_stdout = 0;
		//stdout_reset(info);
	}
	if (info->temp_stdin)
	{
		close(info->temp_in_fd);
		dup2(info->temp_stdin, STDIN_FILENO);
		info->temp_stdin = 0;
		//stdin_reset(info);
	}
	//testare se
	//int fd_out = dup(STDOUT_FILENO) creo un altro file descriptor per stdout
	//dup2(fd,1) imposta 1 come nuovo descriptor di fd e chiuderebbe stdout qualora non avesse un altro file descriptor
	//ora funzioni come printf non scriveranno più sul terminale ma sul file che ha fd
	//dup2(fd_out, 1) dovrebbe reimpostare a 1 il file descriptor di stdout quindi il terminale e printf dovrebbe funzionare normalmente
}


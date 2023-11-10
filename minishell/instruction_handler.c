/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/10 12:19:29 by fgolino          ###   ########.fr       */
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
	matrix_cleaner(&(info->instr_token), info->num_arg);
	// crea una funzione che prende instr_token e rimuove tutte le strighe che hanno \0 in posizione 0
	// cosí eviti che funzioni tipo cat ti dicano che non esiste una stringa vuota perché é dove si
	// trovava prima un redirect
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
			exit (0);
		}
		signal_avoid();
	}
	if (info->tmp_fd)
	{
		tmp_file_creator(info, 3);
		dup2(info->temp_stdin, STDIN_FILENO);
		info->temp_stdin = 0;
	}
	if (info->temp_stdout)
	{
		if (info->temp_out_fd)
			close(info->temp_out_fd);
		dup2(info->temp_stdout, STDOUT_FILENO);
		info->temp_stdout = 0;
		info->temp_out_fd = 0;
		//stdout_reset(info);
	}
	if (info->temp_stdin)
	{
		if (info->temp_in_fd)
			close(info->temp_in_fd);
		dup2(info->temp_stdin, STDIN_FILENO);
		info->temp_stdin = 0;
		info->temp_in_fd = 0;
		//stdin_reset(info);
	}
	//testare se
	//int fd_out = dup(STDOUT_FILENO) creo un altro file descriptor per stdout
	//dup2(fd,1) imposta 1 come nuovo descriptor di fd e chiuderebbe stdout qualora non avesse un altro file descriptor
	//ora funzioni come printf non scriveranno più sul terminale ma sul file che ha fd
	//dup2(fd_out, 1) dovrebbe reimpostare a 1 il file descriptor di stdout quindi il terminale e printf dovrebbe funzionare normalmente
}


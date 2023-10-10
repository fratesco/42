/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/10 02:03:10 by fgolino          ###   ########.fr       */
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
	//while (tokens[len])
	//{
	//	printf("%s\n", tokens[len]);
	//	len++;
	//}
	if (!tokens)
		return (free_matrix(tokens));
	info->instr_token = tokens;
	info->num_arg = len;
}

void	analizer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	dollar_handler(info);
	polish_tokens(info);
	if (ft_strncmp(info->instr_token[0], "pwd", ft_strlen("pwd")) == 0)
		pwd_handler(info);
	else if (ft_strncmp(info->instr_token[0], "echo", ft_strlen("echo")) == 0)
		echo_handler(info);
	else if (ft_strncmp(info->instr_token[0], "cd", ft_strlen("cd")) == 0)
		cd_handler(info);
	else if (ft_strncmp(info->instr_token[0], "env", ft_strlen("env")) == 0)
		env_handler(info);
	else if (ft_strncmp(info->instr_token[0],
			"export", ft_strlen("export")) == 0)
		export_handler(info);
	else if (ft_strncmp(info->instr_token[0], "unset", ft_strlen("unset")) == 0)
		unset_handler(info);
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
	//testare se
	//int fd_out = dup(STDOUT_FILENO) creo un altro file descriptor per stdout
	//dup2(fd,1) imposta 1 come nuovo descriptor di fd e chiuderebbe stdout qualora non avesse un altro file descriptor
	//ora funzioni come printf non scriveranno più sul terminale ma sul file che ha fd
	//dup2(fd_out, 1) dovrebbe reimpostare a 1 il file descriptor di stdout quindi il terminale e printf dovrebbe funzionare normalmente
}

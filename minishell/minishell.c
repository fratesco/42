/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/05 11:11:50 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

void	get_environment(t_info *g_info, char **environment)
{
	char	*tmp;

	g_info->environment = environment;
	g_info->global_path = ft_split((getenv("PATH")), ':');
	g_info->user = ft_strdup(getenv("USER"));
	tmp = ft_strjoin(g_info->user, (":~"));
	free(g_info->user);
	g_info->user = tmp;
	// possiamo far controllare a minishell se esiste almeno un processo con qu4esto nome prma di farlo partire per controllare che sia un minishell dentro minishell
	// utilizzare ps per scrivere i processi in un file
	// bisogna decidere se vogliamo semplicemente creare un interrupt_handler specifico per questo caso che non si mette a scrivere a schermo
	// oppure se vogliamo che il minishell figlio venga gestito come un qualsiasi processo figlio e quindi interrotto da ctrl-c
	signal_rewire();
	g_info->current_path = ft_strdup(getenv("HOME"));
	g_info->temp_stdout = 0;
	chdir(g_info->current_path);
	g_info->instr_len = 0;
	g_info->instr_token = NULL;
	g_info->current_arg = 0;
	g_info->num_arg = 0;
	g_info->received_signal = 0;
}

void	executing(t_info *info)
{
	start(info);
	if (info->num_arg != 0)
		analizer(info);
	if (info->instr_pid != 0)
	{
		while (info->received_signal != info->instr_pid && g_signal != SIGINT)
			info->received_signal = wait(NULL);
	}
	if (g_signal == SIGINT)
	{
		if (info->instr_pid != 0)
			kill(info->instr_pid, SIGINT);
	}
		g_signal = 0;
}

int	main(int argc, char	**argv, char **envp)
{
	t_info	info;

	if (argc > 1)
		exit(0); //aggiungere messaggio del tipo "Minishell takes no input argument"
	get_environment(&info, envp);
	while (1)
	{
		info.instr_pid = 0;
		info.instruction = readline(info.user);
		add_history(info.instruction);
		if (info.instruction == NULL && info.instr_pid == 0)
			break ;
		executing(&info);
		free_stuff(&info, 1);
	}
	free_stuff(&info, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/01 19:03:37 by fgolino          ###   ########.fr       */
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
	signal_rewire();
	g_info->current_path = ft_strdup(getenv("HOME"));
	g_info->temp_stdout = 0;
	chdir(g_info->current_path);
	g_info->instr_len = 0;
	g_info->instr_token = NULL;
	g_info->current_arg = 0;
	g_info->num_arg = 0;
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
		info.instruction = readline(info.user); //la shell della 42 printa il numero della postazione
		add_history(info.instruction);
		if (info.instruction == NULL)
			break ;
		start(&info);
		// probabilmente è meglio se tutto quello che succede da qui in poi è gestito da un processo figlio
		if (info.instr_len != 0)
			analizer(&info);
		//qui il processo genitori si mette in waitpid(0, NULL, NULL) e poi fa ripartire il suo loop
		//wait(NULL);
		if (g_signal == SIGINT)
		{
			if (info.instr_pid != 0)
				kill(info.instr_pid, SIGINT);
			g_signal = 0;
		}
		free_stuff(&info, 1);
	}
	free_stuff(&info, 0);
	return (0);
}

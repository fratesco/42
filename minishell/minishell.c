/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/29 18:08:07 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_environment(t_info *g_info)
{
	char	*tmp;

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

int	main(void)
{
	t_info	info;

	get_environment(&info);
	while (1)
	{
		info.instr_pid = 0;
		info.instruction = readline(info.user); //la shell della 42 printa il numero della postazione
		// probabilmente è meglio se tutto quello che succede da qui in poi è gestito da un processo figlio
		add_history(info.instruction);
		if (info.instruction == NULL)
			break ;
		start(&info);
		if (info.instr_len != 0)
			analizer(&info);
		//qui il processo genitori si mette in waitpid(0, NULL, NULL) e poi fa ripartire il suo loop
		free(info.instruction);
		free_matrix(info.instr_token);
		info.instr_len = 0;
		info.instr_token = NULL;
	}
	free_stuff(info);
	return (0);
}

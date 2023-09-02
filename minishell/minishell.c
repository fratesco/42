/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 17:58:56 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_info	g_info;

int	main(void)
{

	g_info.global_path = ft_split((getenv("PATH")), ':');
	g_info.user = ft_strdup(getenv("USER"));
	g_info.user = ft_strjoin(g_info.user, (">"));
	signal_rewire();
	g_info.current_path = ft_strdup(getenv("HOME"));
	g_info.temp_stdout = 0;
	chdir(g_info.current_path);
	while (1)
	{
		g_info.instr_pid = 0;
		g_info.instruction = readline(g_info.user); //la shell della 42 printa il numero della postazione
		// probabilmente è meglio se tutto quello che succede da qui in poi è gestito da un processo figlio
		add_history(g_info.instruction);
		if (g_info.instruction == NULL)
			break ;
		start();
		if (g_info.instr_len != 0)
			analizer();
		//qui il processo genitori si mette in waitpid(0, NULL, NULL) e poi fa ripartire il suo loop
		free(g_info.instruction);
		free_matrix(g_info.instr_token);
		g_info.instr_token = NULL;
	}
	free_stuff();


	return (0);
}

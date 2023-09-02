/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 12:08:14 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_info	g_info;

int	main(void)
{
	char	*command;
	int		i;

	i = 0;
	g_info.instr_pid = 0;
	g_info.global_path = get_path(getenv("PATH"));
	g_info.user = getenv(("USER"));
	g_info.user = ft_strjoin(g_info.user, (">"));
	signal_rewire();
	while (1)
	{
		g_info.instruction = readline(g_info.user); //la shell della 42 printa il numero della postazione
		// probabilmente è meglio se tutto quello che succede da qui in poi è gestito da un processo figlio
		if (g_info.instruction == NULL)
			exit(0);
		start();
		
		//qui il processo genitori si mette in waitpid(0, NULL, NULL) e poi fa ripartire il suo loop
		g_info.instr_pid = 0;
		free(g_info.instruction);
	}
	free(g_info.user);
	free_matrix(g_info.global_path);

	return (0);
}
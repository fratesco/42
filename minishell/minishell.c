/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:47:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/08/19 17:30:22 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*command;
	int		i;

	i = 0;
	g_info.ins_pid = 0;
	g_info.global_path = get_path(getenv("PATH"));
	//while (info.global_path[i])
	//{
	//	printf("%s\n", info.global_path[i]);
	//	i++;
	//}
	while (1)
	{
		g_info.instruction = readline();
		// probabilmente è meglio se tutto quello che succede da qui in poi è gestito da un processo figlio
		start();
		//qui il processo genitori si mette in waitpid(0, NULL, NULL) e poi fa ripartire il suo loop
		free(g_info.instruction);
	}
	free_matrix(g_info.global_path);

	return (0);
}
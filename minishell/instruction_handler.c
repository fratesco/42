/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/08/19 17:10:14 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start(void)
{
	char	**tokens;
	int		len;

	signal_rewire();
	tokens = ft_split(g_info.instruction, ' ');
	len = 0;
	while (tokens && tokens[len])
		len++;
	if (len == 0)
		return (free_matrix(tokens));
	g_info.instr_len = len;
	free_matrix(tokens);
}
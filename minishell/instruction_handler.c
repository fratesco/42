/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 13:51:07 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	start(void)
{
	char	**tokens;
	int		len;

	tokens = ft_split(g_info.instruction, ' ');
	len = 0;
	while (tokens && tokens[len])
		len++;
	g_info.instr_len = len;
	g_info.instr_token = tokens;
}
void	analizer(void)
{
	int	i;

	i = 0;
	//printf("%s", g_info.instr_token[0]);
	if (ft_strncmp(g_info.instr_token[0], "pwd", ft_strlen("pwd")) == 0)
		pwd_handler();
}
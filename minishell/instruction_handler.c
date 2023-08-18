/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/08/18 15:41:43 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start(char *instruction)
{
	char	**tokens;
	int		len;

	tokens = ft_split(instruction, ' ');
	len = 0;
	while (tokens && tokens[len])
		len++;
	if (len == 0)
		return (free_matrix(tokens));
	
	free_matrix(tokens);
}
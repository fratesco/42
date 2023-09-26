/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/26 18:01:58 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	start(void)
{
	char	**tokens;
	int		len;
	int		j;

	//il problema è che ft_split separa anche in base agli spazi contenuti nelle virgolette, bisognerebbe modificarlo in modo da ingnorare gli spazi tra le virgolette
	//oppure fare prima uno split in base alle virgolette e poi in base agli spazi, il problema è che dovremmo poi unire delle matrici e nasce anche il problema che
	//dobbiamo separare solo le prime coppie di virgolette ogni volta
	tokens = ft_split(g_info.instruction, ' ');
	len = 0;
	if (!tokens)
		return (free_matrix(tokens));
	while (tokens && tokens[len])
	{
		if (check_string(tokens[len]))
		{
			free_matrix(tokens);
			return ;
		}
		len++;
	}
	g_info.instr_token = tokens;
	g_info.instr_len = len;
}

void	analizer(void)
{
	int	i;
	int	j;

	i = 0;
	//printf("%s", g_info.instr_token[0]);
	polish_tokens();
	if (ft_strncmp(g_info.instr_token[0], "pwd", ft_strlen("pwd")) == 0)
		pwd_handler();
	else if (ft_strncmp(g_info.instr_token[0], "echo", ft_strlen("echo")) == 0)
		echo_handler();
	//testare se
	//int fd_out = dup(STDOUT_FILENO) creo un altro file descriptor per stdout
	//dup2(fd,1) imposta 1 come nuovo descriptor di fd e chiuderebbe stdout qualora non avesse un altro file descriptor
	//ora funzioni come printf non scriveranno più sul terminale ma sul file che ha fd
	//dup2(fd_out, 1) dovrebbe reimpostare a 1 il file descriptor di stdout quindi il terminale e printf dovrebbe funzionare normalmente
}

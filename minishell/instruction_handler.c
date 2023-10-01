/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:29:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/01 19:06:49 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	start(t_info *info)
{
	char	**tokens;
	int		len;
	int		j;

	//il problema è che ft_split separa anche in base agli spazi contenuti nelle virgolette, bisognerebbe modificarlo in modo da ingnorare gli spazi tra le virgolette
	//oppure fare prima uno split in base alle virgolette e poi in base agli spazi, il problema è che dovremmo poi unire delle matrici e nasce anche il problema che
	//dobbiamo separare solo le prime coppie di virgolette ogni volta
	if (ft_strncmp(info->instruction, "", 1) == 0)
		return ;
	if (check_string(info->instruction))
		return ;
	tokens = splitter(info->instruction, ' ', ft_strlen(info->instruction), &len);
	printf("%i\n", len);
	len = 0;
	while (tokens[len])
	{
		printf("%s\n", tokens[len]);
		len++;
	}
	//return ;
	if (!tokens)
		return (free_matrix(tokens));
	//ho fatto il check delle quotes non chiuse su tutta la stringa e non solo su quelle splittate
	//while (tokens && tokens[len])
	//{
	//	if (check_string(tokens[len]))
	//	{
	//		free_matrix(tokens);
	//		return ;
	//	}
	//	len++;
	//}
	//aggiungi il check che len < instr_end così si ferma prima di raggiungere l'ipotetica pipe che abbiamio trovato
	while (tokens && tokens[len])
		len++;
	info->instr_token = tokens;
	info->instr_len = len;
}

void	analizer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	//printf("%s", g_info.instr_token[0]);
	polish_tokens(info);
	if (ft_strncmp(info->instr_token[0], "pwd", ft_strlen("pwd")) == 0)
		pwd_handler(info);
	else if (ft_strncmp(info->instr_token[0], "echo", ft_strlen("echo")) == 0)
		echo_handler(info);
	else if (ft_strncmp(info->instr_token[0], "cd", ft_strlen("cd")) == 0)
		cd_handler(info);
	else if (ft_strncmp(info->instr_token[0], "env", ft_strlen("env")) == 0)
		env_handler(info);
	//testare se
	//int fd_out = dup(STDOUT_FILENO) creo un altro file descriptor per stdout
	//dup2(fd,1) imposta 1 come nuovo descriptor di fd e chiuderebbe stdout qualora non avesse un altro file descriptor
	//ora funzioni come printf non scriveranno più sul terminale ma sul file che ha fd
	//dup2(fd_out, 1) dovrebbe reimpostare a 1 il file descriptor di stdout quindi il terminale e printf dovrebbe funzionare normalmente
}

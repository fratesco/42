/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:38:35 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 22:45:45 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix != NULL && matrix[i])
		free(matrix[i++]);
	if (matrix != NULL)
		free(matrix);
}

char	**pipe_finder(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_info.instr_token && g_info.instr_token[i])
	{
		j = 0;
		while (g_info.instr_token[i][j])
		{
			
		}
	}
}

void	free_stuff(void)
{
	free(g_info.user);
	free(g_info.current_path);
	free_matrix(g_info.global_path);
	free_matrix(g_info.instr_token);
	rl_clear_history();
}

int	redirector(void)
{
	int	i;

	i = 0;
	while (g_info.instr_token[i] && g_info.temp_stdout == 0)
	{
		if (ft_strncmp(">", g_info.instr_token[i], 1) == 0)
		{
			if (i + 1 == g_info.instr_len)
			{
				printf("Syntax error\n");
				return (-1);
			}
		}
		i++;
	}
}

//int	check_string(char *str)
//{
//	int	i;
//	int	num_single;
//	int	num_double;
//
//	i = 0;
//	num_single = 0;
//	num_double = 0;
//	while (str && str[i])
//	{
//		if (str[i] == '"')
//		{
//			num_double++;
//			while (str && str[i])
//			{
//				
//			}
//		}
//		else if (str[i] == "'")
//			num_single++;
//	}
//	if ()
//	{
//		printf("Invalid quotes");
//		return (1);
//	}
//	return (0);
//}

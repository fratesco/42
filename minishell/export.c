/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:29:37 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/16 14:01:35 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_handler(t_info *info, int arg)
{
	int i;
	char **tmp;
	
	//if (info->num_arg == 1)
	//	return (export_handler_2(info));
	if (token_checker(info, arg))
		return ;
	tmp = matrix_crusher (info->environment, info->instr_token[i]);
	free_matrix(info->environment);
	info->environment = tmp;
	if ((arg) < info->num_arg - 1)
		export_handler(info, (arg + 1));
	info->exit_status = 0;
}

int token_checker(t_info *info, int arg)
{
	if ((info->instr_token[arg][0] <= 'A' || info->instr_token[arg][0] >= 'Z')
			&& (info->instr_token[arg][0] <= 'a' || info->instr_token[arg][0] >= 'z'))
			return (1);
	return(0);
}

void export_handler_2(t_info *info)
{
	//char **tmp;
	//int	ind;
	//int i;
	//
	//tmp = info->environment;
	//i = -1;
	//while (info->environment[++i])
	//{
	//	ind = alph_index(info);
	//	tmp[i] = info->environment[ind];
	//}
	//i = -1;
	//while(tmp[++i])
	return ;
}

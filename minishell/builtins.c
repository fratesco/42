/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/29 20:33:20 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_handler(t_info *info)
{
	if (redirector(info) == -1)
		return ;
	printf("%s\n", info->current_path);
}

void	echo_handler(t_info *info)
{
	info->current_arg = 1;
	while (info->instr_token[info->current_arg])
	{
		printf("%s ", info->instr_token[info->current_arg]);
		info->current_arg++;
	}
	if (info->instr_token[1]
		&& ft_strncmp(info->instr_token[1], "-n", 2) != 0)
		printf("\n");
	return ;
}

void	cd_handler(t_info *info)
{
	int		i;
	char	*tmp;

	if (info->num_arg < 2)
		chdir(getenv("HOME"));
	if (info->num_arg > 2)
		printf("cd: too many arguments\n");
	if (info->num_arg == 2 && chdir(info->instr_token[1]) != 0)
	{
		i = -1;
		while (info->global_path[++i])
		{
			tmp = triple_join(info->global_path[i], "/", info->instr_token[1]);
			if (!chdir(tmp))
			{
				free(tmp);
				break ;
			}
			else
				free(tmp);
		}
	}
	free(info->current_path);
	info->current_path = getcwd(NULL, 0);
	return ;
}

void	export_handler(t_info *info)
{
	//questa funzione deve poter rendere variabili globali delle variabili create attraverso la shell
	// esempio: >a=5  | ora esiste una variabile locale con valore 5
	// se faccio echo $a | mi scrive 5
	// se chiamo bash e faccio echo $a ! non scrive niente
	// la variabile locale non esiste per un sottoprocesso 
	// se invece faccio export a=5 oppure a=5 e poi export a | la variabile ora esiste per anche per un sottoprocesso
	// quindi se faccio bash>echo $a | mi scrive 5
	//Subshells will have access to all variables from the parent, regardless of their exported state.
	//Subprocesses will only see the exported variables.
}

void	env_handler(t_info *info)
{
	//a quanto pare l'unica soluzione per ottenere le variabili globali è quello di aggiungere "char **envp" agli argomenti del main
	//envp è una matrice che contiene l'environment cioè tutte le variabili globali della shell che ha fatto partire il programma
	//avendo envp è facile fare il comando "env" senza flag, basta fare un loop e scrivere a schermo stringa per stringa envp
}

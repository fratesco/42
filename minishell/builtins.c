/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:20:45 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/16 12:53:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	pwd_handler(t_info *info)
{
	printf("%s\n", info->current_path);
	info->exit_status = 0;
}

void	echo_handler(t_info *info)
{
	info->current_arg = 1;
	while (info->instr_token[info->current_arg])
	{
		printf("%s", info->instr_token[info->current_arg]);
		if (info->instr_token[info->current_arg][0] != 0)
			printf(" ");
		info->current_arg++;
	}
	if (info->instr_token[1]
		&& ft_strncmp(info->instr_token[1], "-n", 2) != 0)
		printf("\n");
	info->exit_status = 0;
	return ;
}

void	cd_handler(t_info *info)
{
	if (info->num_arg < 2)
		chdir(getenv("HOME"));
	if (info->num_arg > 2)
	{
		info->exit_status = 1;
		printf("cd: too many arguments\n");
	}
	if (info->num_arg == 2 && chdir(info->instr_token[1]) != 0)
	{
		info->exit_status = 1;
		if (errno == EACCES)
			printf ("cd : %s : Permission denied\n", info->instr_token[1]);
		else if (errno == ENOTDIR)
			printf ("cd : %s : Not a directory\n", info->instr_token[1]);
		else if (cd_loop(info))
			printf("cd : %s : %s\n", info->instr_token[1], strerror(errno));
		else
			info->exit_status = 0;
	}
	else if (info->num_arg == 2)
		info->exit_status = 0;
	free(info->current_path);
	info->current_path = getcwd(NULL, 0);
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
	// Subshells will have access to all variables from the parent, regardless of their exported state.
	// Subprocesses will only see the exported variables.

	// a quanto pare devo fare in modod che export aggiunga variabili globali alla lista di variabili globali (environment)
	// deve anche poter modificare quelle gia esistenti
	// ogni volta che una variabile globale viene modificata è necessario che tutte le variabili globali salvate in info venagano aggiornate
	// sinceramente non come fare funzionare questa funzione se non aggiungendo stringhe alla fine di environnment. Questo metodo però non verrebbe riconosciuto da getenv()
	// quindi tentare di ottenere una variabile che è stata aggiunta o modificata diverebbe fattibile solo scorrendo tutto le stringhe manualamnte
	info->exit_status = 0;
}

void	env_handler(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// potrei dover aggiungere un check per vedere se ci sono argomenti (che non vanno gestiti) e in caso scrivere un errore
	while (info->environment[i])
	{
		// sembra essere così semplice
		j = 0;
		while (info->environment[i][j])
		{
			if (info->environment[i][j] == '=')
			{
				printf("%s\n", info->environment[i]);
				info->exit_status = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	info->exit_status = 0;
	//a quanto pare l'unica soluzione per ottenere le variabili globali è quello di aggiungere "char **envp" agli argomenti del main
	//envp è una matrice che contiene l'environment cioè tutte le variabili globali della shell che ha fatto partire il programma
	//avendo envp è facile fare il comando "env" senza flag, basta fare un loop e scrivere a schermo stringa per stringa envp
}

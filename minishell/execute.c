/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:29:57 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/02 17:00:28 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	found(t_info *info, char *path)
{
	// qui gli diciamo di usare access per controllare i permessi
	// se è tutto ok allora passiamo allo stadio successivo in cui facciamo partire il programma con exceve
	printf("Trovato!\n");
	if (!access(path, X_OK))
		printf("Ho i permessi\n");
	else
		printf("No puedo\n");
	return 1;
}

void	try_find_do(t_info *info, char *name)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	// questa funzione si occupa di cercare il file, vedere se si possiedono i permessi necessari per esegurilo e eseguire il file
	if (!access(name, F_OK))
		found(info, name);
	else
	{
		while (info->global_path[i])
		{
			tmp = triple_join(info->global_path[i], "/", name);
			if (!access(tmp, F_OK))
			{
				found(info, tmp);
				free(tmp);
				break ;
			}
			free(tmp);
			i++;	
		}
	}
}
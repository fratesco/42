/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:55:47 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/09 15:48:13 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str && (str[i] != '\'') && str[i])
				i++;
		}
		else if (str[i] == '$' && str[i + 1] != ' ')
			return (i);
		i++;
	}
	return (-1);
}

char	*no_env(int start, int end, char *str)
{
	char	*tmp;

	tmp = (char *)malloc((ft_strlen(str) - (start - end)) * sizeof(char));
	ft_strlcpy(tmp, str, (start + 1));
	ft_strlcpy(&tmp[start], &str[end], (ft_strlen(str) - (start - end)));
	printf("%s\n", tmp);
	free(str);
	if (check_dollar(tmp) >= 0)
		tmp = dollar_remover(tmp, check_dollar(tmp));
	return (tmp);
}

char	*dollar_remover(char *str, int pos)
{
	int		i;
	char	*tmp;
	char	*env;

	i = pos + 1;
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '$')
		i++;
	tmp = (char *)malloc((1 + i + 1 - pos) * sizeof(char));
	ft_strlcpy(tmp, &str[pos + 1], (i - pos));
	env = getenv(tmp);
	free(tmp);
	if (!env)
		return (no_env(pos, i, str));
	tmp = (char *)malloc((ft_strlen(str) + i - pos + ft_strlen(env) + 3)
			* sizeof(char));
	ft_strlcpy(tmp, str, (pos + 1));
	ft_strlcpy(&tmp[pos], env, ft_strlen(env - 1));
	if (str[i])
		ft_strlcpy(&tmp[ft_strlen(tmp)], &str[i], 
			(ft_strlen(str) - 1 + ft_strlen(tmp)));
	free(str);
	if (check_dollar(tmp) >= 0)
		tmp = dollar_remover(tmp, check_dollar(tmp));
	return (tmp);
}

void	dollar_handler(t_info *info)
{
	int		i;
	int		pos;
	char	*tmp;

	i = 0;
	pos = -1;
	while (info->instr_token[i])
	{
		pos = check_dollar(info->instr_token[i]);
		if (pos >= 0)
			info->instr_token[i] = dollar_remover(info->instr_token[i], pos);
		i++;
	}
}
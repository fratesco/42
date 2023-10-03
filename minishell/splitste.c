/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:44:02 by srapuano          #+#    #+#             */
/*   Updated: 2023/10/03 16:48:33 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	no_words(char *av, char sep, int stop)
{
	int	i;

	i = 0;
	while (av[i] && i != stop)
	{
		if (av[i] != sep)
			return (0);
		i++;
	}
	return (1);
}

int	ft_word_counter(char *s, char c, int stop)
{
	int	i;
	int	p;
	char t;

	i = 0;
	p = 0;
	while (s[i] && i != stop)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != 0 && s[i] != c && i != stop)
			p++;
		while (s[i] != c && s[i] != '\0' && i != stop)
		{
			if (s[i] == '\'' || s[i] == '"')
			{
				t = s[i];
				i++;
				while (s[i] != '\0' && s[i] != t)
					i++;
			}
			i++;
		}
	}
	return (p);
}

int	ft_word_len(char *s, int *start, char sep, int stop)
{
	int	i;

	i = 0;
	while (s[*start + i] != sep && s[*start + i] != 0 && (*start + i) != stop)
	{
		if (s[*start + i] == '\'')
		{
			i++;
			while (s[*start + i] != '\0' && s[*start + i] != '\'')
				i++;
		}
		else if (s[*start + i] == '"')
		{
			i++;
			while (s[*start + i] != '\0' && s[*start + i] != '"')
				i++;
		}
		i++;
	}
	return (i);
}

char	*ft_substr_split(char *s, int *start, char sep, int stop)
{
	char	*s_word;
	int		i;
	char t;

	i = 0;
	
	s_word = malloc((ft_word_len(s, start, sep, stop) + 1) * sizeof(char));
	
	if (!s_word)
		return (NULL);
	while (s[*start] != sep && s[*start] != 0 && *start != stop)
	{
		if (s[*start] == '\'' || s[*start] == '"')
		{
			t = s[*start];
			s_word[i++] = s[(*start)++];
			while (s[*start] != '\0' && s[*start] != t)
				s_word[i++] = s[(*start)++];
		}
		s_word[i++] = s[(*start)++];

	}
	
	s_word[i] = '\0';
	return (s_word);
}

char	**splitter(char *av, char sep, int stop, int *ac)
{
	char	**splitted;
	int		i;
	int		start;

	if (!av || no_words(av, sep, stop))
		return (NULL);
	*ac = ft_word_counter((char *)av, sep, stop);
	splitted = malloc((*ac + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	start = 0;
	while (i < *ac && av[start] != 0 && start != stop)
	{
		while (av[start] == sep && av[start])
			start++;
		if (av[start] != sep && av[start] && start != stop)
			splitted[i++] = ft_substr_split((char *)av, &start, sep, stop);
	}
	splitted[i] = 0;
	return (splitted);
}

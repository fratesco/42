/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:44:02 by srapuano          #+#    #+#             */
/*   Updated: 2023/09/29 20:36:30 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"

int no_words(char *av, int stop)
{
	int i;

	i = 0;
	while(av[i] && av[i] != stop)
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_word_counter(char *s, char c, int stop)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (s[i] && s[i] != stop && p++ >= 0)
	{
		while (s[i] != '\0' && s[i] == c )
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i] == '\'')
			{
				while (s[i] != '\0' && s[i] != '\'')
					i++;
			}
			else if  (s[i] == '"')
			{
				while (s[i] != '\0' && s[i] != '"')
					i++;
			}
			i++;
		}
	}	
	return (p);
}

int	ft_word_len(char *s, int start, char sep, int stop)
{
	int	i;

	i = 0;
	while (s[start + i] != sep && s[start + i] != 0 && s[start + i] != stop)
	{
		if (s[start + i] == '\'')
		{
			while (s[start + i] != '\0' && s[start + i] != '\'')
				i++;
		}
		else if  (s[start + i] == '"')
		{
			while (s[start + i] != '\0' && s[start + i] != '"')
				i++;
		}
		i++;
	}
	return (i);
}

char	*ft_substr_split(char *s, int start, char sep, int stop)
{
	char	*s_word;
	int		len;
	int		i;

	i = 0;
	len = ft_word_len(s, start, sep, stop);
	s_word = malloc((len + 1) * sizeof(char));
	if (!s_word)
		return (NULL);
	while (s[start] != sep && s[start] != 0 && s[start] != stop)
	{
		if (s[start + i] == '\'')
		{
			while (s[start + i] != '\0' && s[start + i] != '\'')
				s_word[i++] = s[start++];
		}
		else if  (s[start + i] == '"')
		{
			while (s[start + i] != '\0' && s[start + i] != '"')
				s_word[i++] = s[start++];
		}
		s_word[i++] = s[start++];
	}
	s_word[i] = '\0';
	return (s_word);
}

char	**ft_split(char *av, int stop, int *ac)
{
	char	**splitted;
	int		i;
	int		start;

	if (!av || no_words(av, stop))
		return (NULL);
	*ac = ft_word_counter((char *)av, ' ', stop);
	splitted = malloc((*ac + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	start = 0;
	while (i < *ac && av[start] != 0 && av[start] != stop)
	{
		while (av[start] ==' ' && av[start])
			start++;
		if (av[start] !=' ' && av[start])
			splitted[i++] = ft_substr_split((char *)av, start,' ', stop);
		while (av[start] !=' ' && av[start] && av[start] != stop)
	 	{
			if (av[start] == '\'')
			{
				while (av[start] != '\0' && av[start] != '\'')
					start++;
			}
			else if  (av[start] == '"')
			{
				while (av[start] != '\0' && av[start] != '"')
					start++;
			}
			start++;
		}
	}
	splitted[i] = 0;
	return (splitted);
}

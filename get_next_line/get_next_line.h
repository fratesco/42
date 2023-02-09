/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:44:33 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/09 11:58:20 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define FOUND 1
# define NOTHING 0
# define INVALID -1

# include <unistd.h>
# include <stdlib.h>

char	*flow_lines(char *str, int len, char *rest);
int		check_new(char	*str);
char	*hope_it_works(char *buffer, int len, int fd, char *rest);
char	*get_next_line(int fd);
int		ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
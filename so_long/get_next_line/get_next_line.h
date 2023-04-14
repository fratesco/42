/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:05:13 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/14 11:07:51 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char		*get_next_line(int fd);
char		*get_broken_line(int fd, char *brokenl);
char		*get_fixed_line(const char *brokenl);
char		*get_next_brokenl(char *brokenl);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, int n);

#endif

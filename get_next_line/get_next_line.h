/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:03:11 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/03 15:20:56 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

#  include <unistd.h>

typedef enum mybool{FALSE, TRUE}	t_bool;

size_t	ft_strlen(char	*str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*parse_file(int fd);
char	*line_parsing(char	*str, int fd);
char	*ft_strjoin(char const *s1, char const *s2);

# endif
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:38:34 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/20 18:11:29 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int				ft_isalpha(int letter);
int				ft_isdigit(int i);
int				ft_isalnum(int c);
int				ft_isascii(int c);
size_t			ft_strlen(char const *str);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(char *str1, char *str2, size_t n);
void			*ft_memset(void *buffer, int byte, size_t len);
void			ft_bzero(void *str, size_t len);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memcpy(void *dst, void *src, size_t len);
char			*ft_strchr(char *str, int c);
char			*ft_strnstr(char *str, char *to_find, size_t len);
size_t			*ft_strlcpy(char *dest, char *src, size_t size);
void			*ft_memchr(void *str, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
int				ft_atoi(char *str);
size_t			ft_strlcat(char *dst, char *src, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *str1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
#endif
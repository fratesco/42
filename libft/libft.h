/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:38:34 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/27 16:45:24 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_list
{
	void			*content;
	struct t_list	*next;
}					t_list;
int				ft_isalpha(int letter);
int				ft_isdigit(int i);
int				ft_isalnum(int c);
int				ft_isascii(int c);
size_t			ft_strlen(char const *str);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memset(void *buffer, int byte, size_t len);
void			ft_bzero(void *str, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, void *src, size_t len);
char			*ft_strchr(char *str, int c);
char			*ft_strrchr(char *str, int c);
char			*ft_strnstr(char *str, char *to_find, size_t len);
size_t			ft_strlcpy(char *dest, char const *src, size_t size);
void			*ft_memchr(void *str, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
int				ft_atoi(char *str);
size_t			ft_strlcat(char *dst, char const *src, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char const *str1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
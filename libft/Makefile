# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 17:38:45 by fgolino           #+#    #+#              #
#    Updated: 2023/01/23 18:14:04 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	:=	ft_itoa.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
			ft_strrchr.c ft_strtrim.c ft_substring.c ft_tolower.c ft_toupper.c\

CFLAGS	:=	-Werror -Wall -Wextra

OBJS	:=	$(SRCS:.c=.o)

NAME	:=	libft.a

CC		:=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
clean:
			rm -f $(OBJS)
fclean:		clean
			rm -f $(NAME)
re:			fclean all




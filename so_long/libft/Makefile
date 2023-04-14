# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 17:38:45 by fgolino           #+#    #+#              #
#    Updated: 2023/01/27 16:45:36 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	:=	ft_itoa.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_atoi.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c\
			ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstmap.c\

CFLAGS	:=	-Werror -Wall -Wextra

OBJS	:=	$(SRCS:.c=.o)

BONUS   :=  ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c\
			ft_lstlast.c ft_lstnew.c ft_lstsize.c\
			
BOBJS	:=  $(BONUS:.c=.o)

NAME	:=	libft.a

CC		:=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
clean:
			rm -f $(OBJS) $(BOBJS)
fclean:		clean
			rm -f $(NAME)
			
re:			fclean $(NAME)

bonus:		$(BOBJS)

			ar rc $(NAME) $(BOBJS)

.PHONY :
			all clean fclean re bonus




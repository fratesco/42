# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:10:11 by fgolino           #+#    #+#              #
#    Updated: 2023/02/01 15:56:28 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	:=	printf_check.c ft_printf.c ft_putnbr_base.c 

OBJS	:=	$(SRCS:.c=.o)

FLAGS	:= -Werror -Wextra -Wall

NAME	:=	libftprintf.a

CC		:=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:
			all clean fclean re
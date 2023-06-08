# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 10:45:15 by fgolino           #+#    #+#              #
#    Updated: 2023/06/08 05:14:31 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo

SRC		:= philosophers.c utils.c philo_stuff.c more_stuff.c

OBJ		:= $(SRC:.c=.o)

CC		:= gcc

FLAGS	:= -Wextra -Werror -Wall

$(NAME) : $(OBJ)
		 $(CC) $(FLAGS) $(OBJ) -o $(NAME)

all		: $(NAME)

clean	:
		 rm -f $(OBJ)

fclean	: clean
		 rm -f $(NAME)

re		: fclean all

.PHONY	:
		 all clean fclean re
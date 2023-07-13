# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 10:45:15 by fgolino           #+#    #+#              #
#    Updated: 2023/07/13 13:10:32 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo_bonus

SRC		:= philosophers_bonus.c philo_bonus.c more_utils.c bonus_utils.c

OBJ		:= $(SRC:.c=.o)

CC		:= gcc

FLAGS	:= -Wextra -Werror -Wall

$(NAME) : $(OBJ)
		 $(CC) $(FLAGS) -g $(OBJ) -o $(NAME)

all		: $(NAME)

clean	:
		 rm -f $(OBJ)

fclean	: clean
		 rm -f $(NAME)

re		: fclean all

.PHONY	:
		 all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:56:46 by fgolino           #+#    #+#              #
#    Updated: 2023/08/18 15:40:22 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := minishell.c instruction_handler.c utils.c

OBJ := $(SRC:.c=.o)

NAME := minishell

LIBFT := libft/

CC := gcc

FLAGS := -Wextra -Werror -Wall 

$(NAME) : $(OBJ)
		make -C $(LIBFT)
		$(CC) $(FLAGS) -g $(OBJ) -o $(NAME) libft/libft.a -lreadline

all : $(NAME)

clean :
		cd $(LIBFT); make clean
		rm -r $(OBJ)

fclean : clean
		cd $(LIBFT); make fclean
		rm -r $(NAME)

re : fclean all

.PHONY : 
		all clean fclean re
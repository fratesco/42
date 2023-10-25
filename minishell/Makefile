# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:56:46 by fgolino           #+#    #+#              #
#    Updated: 2023/10/25 20:14:34 by srapuano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := minishell.c instruction_handler.c utils.c signal.c builtins.c quotes.c quotes2.c splitste.c builtins2.c execute.c pipes.c signal2.c dollar.c matrix.c redirect.c\
	   redirect2.c export_checker.c

OBJ := $(SRC:.c=.o)

NAME := minishell

LIBFT := libft/

CC := gcc

FLAGS := -Wextra -Werror -Wall 

all : $(NAME)
	  @echo Minishell compiled successfully

$(NAME) : $(OBJ)
		make -s -C $(LIBFT)
		$(CC) $(FLAGS) -g $(OBJ) -o $(NAME) libft/libft.a -lreadline


clean :
		@cd $(LIBFT); make clean -s 
		@rm -f $(OBJ)
		@echo Objects cleaned

fclean : clean
		@cd $(LIBFT); make fclean -s 
		@rm -f $(NAME)
		@echo Minishell cleaned

re : fclean all

.SILENT : $(OBJ) $(NAME)

.PHONY : 
		all clean fclean re
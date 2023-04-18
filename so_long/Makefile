# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 09:52:24 by fgolino           #+#    #+#              #
#    Updated: 2023/04/18 18:08:24 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:= so_long.c map_handler.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils.c\
		   utils2.c\

OBJ		:= $(SRC:.c=.o)

CC		:= gcc

NAME	:= so_long

FLAGS	:= -Wextra -Werror -Wall

LIBFT	:= libft/

PRINTF	:= ft_printf/

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT)
		make -C $(PRINTF)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a ft_printf/libftprintf.a

clean:
		cd $(LIBFT); make clean
		cd $(PRINTF); make clean
		rm -f $(OBJ)

fclean: clean
		cd $(LIBFT); make fclean
		cd $(PRINTF); make fclean
		rm -f $(NAME)

re:	fclean all

.PHONY:
		all re clean fclean
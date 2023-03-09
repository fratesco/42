# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 18:34:13 by fgolino           #+#    #+#              #
#    Updated: 2023/03/09 16:47:56 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:= push_swap.c instructions.c brain.c

OBJ		:= $(SRC:.c=.o)

CC		:= gcc

NAME	:= push_swap

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
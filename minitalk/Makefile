# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 12:07:42 by fgolino           #+#    #+#              #
#    Updated: 2023/03/08 18:46:50 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1  := client.c

SRC2  := server.c

FLAGS := -Wall -Wextra -Werror

NAME1 := client

NAME2 := server

LIBFT = libft/
PRINTF = ft_printf/

CC 	  := gcc

all:      $(NAME1) $(NAME2)

$(NAME1): client.o
			make -C $(PRINTF)
			make -C $(LIBFT)
			$(CC) $(FLAGS) -o $(NAME1) libft/libft.a ft_printf/libftprintf.a client.o
			
$(NAME2): server.o
			make -C $(PRINTF)
			make -C $(LIBFT)
			$(CC) $(FLAGS) -o $(NAME2) libft/libft.a ft_printf/libftprintf.a server.o

clean:   
			cd $(LIBFT) make clean
			cd $(PRINTF) make clean
			rm -f client.o server.o
fclean:   clean
			cd $(PRINTF) make fclean 
			cd $(LIBFT) make fclean 
			rm -f $(NAME1) $(NAME2)

re: fclean re

.PHONY: 
		all clean re fclean
 
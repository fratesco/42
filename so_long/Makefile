# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 09:52:24 by fgolino           #+#    #+#              #
#    Updated: 2023/04/20 15:17:31 by fgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:= so_long.c map/map_handler.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c map/utils.c\
		   map/utils2.c\

OBJ		:= $(SRC:.c=.o)

CC		:= gcc

NAME	:= so_long

FLAGS	:= -Wextra -Werror -Wall

LIBFT	:= libft/

PRINTF	:= ft_printf/

MLX     := minilibx_opengl_20191021/

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT)
		make -C $(PRINTF)
		make -C $(MLX)
		$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit minilibx_opengl_20191021/libmlx.a libft/libft.a ft_printf/libftprintf.a -o $(NAME)   

clean:
		cd $(LIBFT); make clean
		cd $(PRINTF); make clean
		cd $(MLX); make clean
		rm -f $(OBJ)

fclean: clean
		cd $(LIBFT); make fclean
		cd $(PRINTF); make fclean
		rm -f $(NAME)

re:	fclean all

.PHONY:
		all re clean fclean
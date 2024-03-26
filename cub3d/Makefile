SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

CC := gcc

NAME := cub3d

FLAGS := -I/usr/include -Imlx_linux -O3 -Wall -Wextra -Werror

all : $(NAME)
		@echo $(NAME) compiled successfully!

$(NAME) : $(OBJ)
		@make -s -C libft/
		$(CC) $(CFLAGS) -g $(OBJ) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean : 
		@make -s -C libft/ clean
		@rm -f $(OBJ)
		@echo object cleaned

fclean : clean
		@make -s -C libft/ fclean
		@rm -f $(NAME)
		@echo $(NAME) cleaned

re : fclean all

.SILENT : $(NAME) $(OBJ) 

.PHONY :
		all clean fclean re

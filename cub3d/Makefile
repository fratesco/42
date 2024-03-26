SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

CC := gcc

NAME := cub3d

FLAGS := -I/usr/include -Imlx_linux -O3 -Wall -Wextra -Werror

all : $(NAME)
		@echo $(NAME) compiled successfully!

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) -g $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean : 
		@rm -f $(OBJ)
		@echo object cleaned

fclean : clean
		@rm -f $(NAME)
		@echo $(NAME) cleaned

re : fclean all

.SILENT : $(NAME) $(OBJ)

.PHONY :
		all clean fclean re

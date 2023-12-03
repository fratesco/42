SRC := tests.cpp Account.cpp

OBJ := $(SRC:.c=.o)

CC := c++

NAME := test

FLAGS := -Wextra -Wall -Werror

STD := -std=c++98

all : $(NAME)
		@echo test compiled successfully!

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -g $(OBJ) -o $(NAME)

clean : 
		@rm -f $(OBJ)
		@echo object cleaned

fclean : clean
		@rm -f $(NAME)
		@echo $(NAME) cleaned

re : fclean all

std : $(OBJ)
		$(CC) $(FLAGS) $(STD) -g $(OBJ) -o $(NAME)
		@echo test compiled with $(STD) flag successfully

.SILENT : $(NAME) $(OBJ)

.PHONY :
		all clean fclean re std

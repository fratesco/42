SRC := megaphone.cpp

OBJ := $(SRC:.c=.o)

CC := c++

FLAGS := -Werror -Wextra -Wall

STD := -std=c++98

NAME := megaphone

all : $(NAME)
	  @echo $(NAME) compiled successfully

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -g $(OBJ) -o $(NAME)

std : $(OBJ)
		$(CC) $(FLAGS) $(STD) -g $(OBJ) -o $(NAME)

clean : 
		@rm -f $(OBJ)
		@echo Objects cleaned

fclean : clean
		@rm -f $(NAME)
		@echo $(NAME) cleaned

re : fclean all

.PHONY :
		all clean fclean re
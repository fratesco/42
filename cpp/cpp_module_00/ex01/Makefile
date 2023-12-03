SRC := PhoneBook.cpp Contact.cpp main.cpp

OBJ := $(SRC:.cpp=.o)

CC := c++

FLAGS := -Werror -Wextra -Wall

STD := -std=c++98

NAME := phonebook

all : $(NAME)
	  @echo $(NAME) compiled successfully

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -g $(OBJ) -o $(NAME)

std : $(OBJ)
		$(CC) $(FLAGS) $(STD) -g $(OBJ) -o $(NAME)
		echo compiled with -std=c++98 flag!

clean : 
		@rm -f $(OBJ)
		@echo Objects cleaned

fclean : clean
		@rm -f $(NAME)
		@echo $(NAME) cleaned

re : fclean all

.SILENT: $(NAME) $(OBJ)

.PHONY :
		all clean fclean re
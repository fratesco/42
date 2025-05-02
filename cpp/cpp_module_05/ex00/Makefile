SRC := $(wildcard *.cpp)

OBJ := $(SRC:.cpp=.o)

CC := c++

NAME := bureaucrat

FLAGS := -Wextra -Wall -Werror

STD := -std=c++98

%.o: %.cpp
		$(CC) $(FLAGS) $(STD) -c $< -o $@

all : $(NAME)
		@echo $(NAME) compiled successfully!

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
		@echo $(NAME) compiled with $(STD) flag successfully

.SILENT : $(NAME) $(OBJ)

.PHONY :
		all clean fclean re std

NAME = rush-02

CFLAGS = -Wall -Wextra -Werror
SRC = string.c dictionary.c reading.c parsing.c printing.c stringmath.c stuff.c solver.c main.c

all: $(NAME)

$(NAME):
	cc $(CFLAGS) $(SRC)
	mv a.out $(NAME)

clean:
	rm $(NAME) functions.h.gch

fclean:
	rm -f $(NAME) functions.h.gch

re: fclean all

.PHONY: all clean fclean re
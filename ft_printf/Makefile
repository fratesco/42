
SRCS	:=

OBJS	:=	$(SRCS:.c=.o)

FLAGS	:=

NAME	:=	libftprintf.a

CC		:=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:
			all clean fclean re
NAME := libasm.a

SRCS := $(wildcard *.s)

OBJS := $(SRCS:.s=.o)

NASM := nasm

FLAGS:= -f elf64

%.o: %.s
		$(NASM) $(FLAGS) $< -o $@

all: $(NAME)
		@echo $(NAME) archive created successfully!

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS) #dovrebbe creare l'archivio a partire da tutti i file oggetto
clean: 
		@rm -f $(OBJS)
		@echo object files cleaned 
fclean: clean
		@rm -f $(NAME)
		@echo $(NAME) cleaned

re: fclean all

.SILENT : $(NAME) $(OBJS)

.PHONY : 
		all clean fclean re
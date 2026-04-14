SRCS := $(wildcard *.c)
NAMES := $(SRCS:.c=)
OBJS := $(SRCS:.c=.o)

CC := clang

FLAGS := -Werror -Wall -Wextra

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAMES)

$(NAMES) : $(OBJS)
			for words in $(NAMES); do \
				$(CC) $(FLAGS) $$words.o -o $$words; \
				echo $$words compiled; \
			done


test1: $(NAMES)
		@./Colleen > tmp ; diff Colleen.c tmp
test2: $(NAMES)
		@./Grace ; diff Grace.c Grace_kid.c ; rm Grace_kid.c

clean:
		rm $(OBJS) 2>/dev/null; \
			if [ $$? -eq 0 ] ; then \
				echo "object files cleaned!"; \
			else \
				echo "nothing to clean"; \
			fi

cleantest:
		@rm -f tmp
		@echo tests cleaned 

fclean: clean cleantest
		for words in $(NAMES); do { \
			rm $$words 2>/dev/null; \
			if [ $$? -eq 0 ]; then \
				echo $$words cleaned!; \
			else \
				echo "no $$words to clean"; \
			fi \
		} \
		done

re: fclean all

.SILENT : re cleantest test1 all clean fclean $(NAMES) $(OBJS)

.PHONY : 
		all clean fclean re test cleantest
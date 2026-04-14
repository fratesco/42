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
				$(CC) $(FLAGS) $(OBJS) -o $$words; \
				echo $$words compiled; \
			done


test_1: $(NAMES)
		@./Colleen > tmp ; diff Colleen.c tmp

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

.SILENT : re cleantest test_1 all clean fclean $(NAMES) $(OBJS)

.PHONY : 
		all clean fclean re test cleantest
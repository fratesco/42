SRCS := $(wildcard *.c)
NAMES := $(SRCS:.c=)
OBJS := $(SRCS:.c=.o)
SHELL := /bin/bash

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
test3: $(NAMES)
		@mkdir -p tmp; cp Sully tmp/; cd tmp/; ./Sully ; ls -al | grep Sully | wc -l ; rm -rf tmp
		./Sully ; 
		for int in {0..5}; do { \
		diff Sully_$$int.c Sully.c;\
		echo "" ;  #se non metto un comando qui il make file mi da errore \
		} done
		@rm -f Sully_{5..0}.c Sully_{5..0}.o Sully_{5..0}
		

sullyclean:
		@rm -f Sully_{5..0}.c Sully_{5..0}.o Sully_{5..0}

clean:
		rm $(OBJS) 2>/dev/null; \
			if [ $$? -eq 0 ] ; then \
				echo "object files cleaned!"; \
			else \
				echo "nothing to clean"; \
			fi

cleantest:
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

.SILENT : re cleantest test1 test2 test3 sullyclean all clean fclean $(NAMES) $(OBJS)

.PHONY : 
		all clean fclean re test cleantest sullyclean test1 test2 test3
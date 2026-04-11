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

#ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -m elf_x86_64 ft_strlen.o main.o -o manual_link.out -lc /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crtn.o -pie

#ld linker utilizzato
#-dynamic-linker /lib64/ld-linux-x86-64.so.2  utilizza un dynamic linker diverso, sembra essere necessario quando si linkano objects creati a partire da c
#-m elf_x86_64 		   emulazione per poter linkare file oggetto elf64
#ft_strlen.o main.o    i file oggetto da linkare
#-o manual_link.out    nome del file output
#-lc                   dice a ld di cercare una libreria di nome libc.a o libc.so nei path da lui noti
#per aggiungere un path ld utilizzare la flag -L
#tenere a mente che -l aggiunge in automatico "lib" prima del nome specificato (-lc = libc), per aggiungere un nome specifico utilizzare -l:libc.a 
#si possono aggiungere librerie in maniera diretta scrivendo il path
#/usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crtn.o  tre file oggetto necessari per linkare i file oggetto dove il main é in c
#contengono cose come entrypoint (main invece di _start) e endpoint. senza questi file il return alla fine del main manda in segfault
#-pie position independent executable
#le librerie devono essere sempre specificate dopo i file oggetto che hanno le reference alle definizioni contenute nei file oggetto
#il linker lavora in ordine e cerca nelle librerie solo i le reference che non ha trovato prima
#questo vale solo per le librerie e non i file oggetto, il loro ordine non ha importanza
.SILENT : $(NAME) $(OBJS)

.PHONY : 
		all clean fclean re
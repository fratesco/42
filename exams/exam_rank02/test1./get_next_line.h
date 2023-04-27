#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf.c"

char *get_next_line(int fd);

#endif
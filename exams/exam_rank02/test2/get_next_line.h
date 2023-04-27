#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.c"
#include <stdlib.h>

char *get_next_line(int fd);

#endif
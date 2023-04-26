#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd);

#endif
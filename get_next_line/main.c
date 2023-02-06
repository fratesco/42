#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main	()
{
	int fd = open("/Users/fgolino/42_git/get_next_line/tester/files/41_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
}
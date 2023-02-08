#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main	()
{
	int fd = open("/Users/fgolino/42_git/get_next_line/tester/files/41_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);


}
//98765432109876543210987654321098765432109
//98765432109876543210987654321098765432109\n


#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main ()
{
	int fd = open ("/Users/fgolino/42_git/get_next_line/tester/files/nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
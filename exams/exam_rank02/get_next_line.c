#include "get_next_line.h"
#include "stdio.h"

char *get_next_line (int fd)
{
	if (BUFFER_SIZE <= 0)
		return (0);
	int i= 0;
	int rea = 0;
	char c;
	char *tmp  = (char *)malloc(100000);
	while ((rea = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		tmp[i++] = c;
		if (c == '\n')
			break;
	}
	tmp[i] = 0;
	if (rea == -1 || i == 0 || (!tmp[i - 1] && !rea))
		return (free(tmp), (char* )0);
	return (tmp);
}

int main (void)
{
	int fd = open("suca", O_RDONLY);
	printf("%i : ", printf("%s", get_next_line(fd)));
	return 0;
}
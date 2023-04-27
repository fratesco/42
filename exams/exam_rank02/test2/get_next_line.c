#include "get_next_line.h"

char *get_next_line(int fd)
{
	int rd = 0;
	int i = 0;
	char c;
	if (BUFFER_SIZE < 1)
		return (0);
	char *buffer = (char *)malloc(100000);
	while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1) > 0))
	{
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	buffer[i] = 0;
	if (rd == -1 || i == 0 || (!rd && !buffer[i - 1]))
		return (free(buffer), NULL);
	return (buffer);
}

int main (void)
{
	int fd = open("suca", O_RDONLY);
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	close(fd);
}
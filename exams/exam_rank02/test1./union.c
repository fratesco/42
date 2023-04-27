#include <unistd.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	int i, j = 0;
	while (argv[1][i++]);
	while (argv[2][j++]);
	char *tmp = (char *)malloc((i + j + 1) * sizeof(char));
	i = 0, j = 0;
	while (argv[1][i])
		tmp[i] = argv[1][i], i++;
	while (argv[2][j])
		tmp[i + j] = argv[2][j], j++;
	tmp[i + j] = 0;
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (j < i && tmp[i] != tmp[j++]);
		if (j == i )
			write(1, &tmp[i], 1);
		i++;
	}
	free(tmp);
	return (0);
}
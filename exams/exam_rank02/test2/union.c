#include <unistd.h>
#include <stdlib.h>

int checker(char c, char *str, int len)
{
	int i = 0;
	while (str && str[i] && (i < len || len == -1))
	{
		if (str[i]==c)
			return 1;
		i++;
	}
	return 0;
}

int main (int argc, char **argv)
{
	int i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!checker(argv[1][i], argv[1], i))
				write(1, &argv[1][i], 1);
				i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!checker(argv[2][i], argv[1], -1) && !checker(argv[2][i], argv[2], i))
				write(1, &argv[2][i], 1);
				i++;
		}
	}
	write(1,"\n", 1);
	return 0;
}
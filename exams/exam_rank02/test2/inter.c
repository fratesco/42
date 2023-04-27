#include <unistd.h>
#include <stdlib.h>

int checker (char c, char *str, int lenght)
{
	int i = 0;

	while (str && str[i] && (i < lenght || (lenght == -1)))
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		int i =0;

		while (argv[1][i])
		{
			if (!checker(argv[1][i], argv[1], i) && checker(argv[1][i], argv[2], -1))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1,"\n", 1);
	return 0;
}

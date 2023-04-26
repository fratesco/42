#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i, j, k,z = 0;
		while (argv[1][i])
		{
			j = 0;
			while ((j < i && argv[1][j] != argv[1][i]) || (i == 0 && z == 0))
			{
				k = 0;
				while (argv[2][k])
				{
					if (argv[2][k] == argv[1][i])
					{
						write(1, &argv[1][i], 1);
						z++;
						break ;
					}
					k++;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n",1);
	return (0);
}
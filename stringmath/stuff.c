#include <stdlib.h>

char	*create_str(int lenght)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (lenght + 1));
	return (result);
}
char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

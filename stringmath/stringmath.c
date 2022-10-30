#include "functions.h"

int	str_lenght(char *str);

int	power(int e, int b)
{
	int	base;

	base = b;
	while (e - 1 > 1)
	{
		b = b * base;
		e--;
	}
	return (b);
}
char	num_to_str(int num)
{
	char	*str;
	int i;
	int temp;

	i = 0;
	temp = num;
	while(temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	while (i >= 0)
	{
		str[i] = num % 10;
		num = num / 10;
	}
	result (str);
}

char	*sub_num_str(char *a, char *b)
{
	int i;
	int res;
	int remainder;
	int pow;
	char *first_num;

	i = strlenght(a);
	first_num = ft_strcpy(new_str(a), a);
	pow = 0;
	while (i >= 0)
	{
		remainder = 0;
		if((first_num[i] - b[i]) < 0)
		{
			remainder = 1;
			res += (- 1 * (first_num[i] - b[i]) * power(pow, 10)); 
		}
		else
			res += ((first_num[i] - b[i]) * power(pow, 10 ));
		if (i > 0)
			first_num[i - 1] -= remainder;
		i--;
	}
	result = num_to_str(res);
	return (result);	
}


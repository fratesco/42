#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void put_str(char *str, int *size)
{
	int i = 0;
	while (str && str[i++]);
	(!str) ? (*size+=write(1, "(null)", 6)) : (*size +=write(1, str++, i));
}

void put_base(long long int num, char *base, int b, int *size)
{
	if (num < 0)
	{
		*size += write(1, "-", 1);
		num = -num;
	}
	if (num >= b)
		put_base(num / b, base , b, size);
	*size+=write(1, &base[num % b], 1);
}

int ft_printf(char *str, ...)
{
	va_list arg;
	int size = 0;
	va_start(arg, str);

	while (str && *str)
	{
		if (*str == '%' && *(str + 1) && *(str + 1) == 's')
			put_str(va_arg(arg, char *), &size), str++;
		else if (*str == '%' && *(str + 1) && *(str + 1) == 'x')
			put_base(va_arg(arg, unsigned int ), "0123456789abcdef", 16, &size), str++;
		else if (*str == '%' && *(str + 1) && *(str + 1) == 'd')
			put_base(va_arg(arg, int),"0123456789", 10, &size), str++;
		else
			size += write(1, str, 1);
		str++;
	}
	return (va_end(arg), size);
}

//int main (void)
//{
//	ft_printf("%d", printf("coseacaso\n%d\n%x\n", 2147483648, 64));
//	return (0);
//}
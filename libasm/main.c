#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char *str);
char *ft_strcpy(char *dest, const char *src);

int main(int argc, char **argv)
{
        char *str = ft_strcpy(malloc(sizeof(char)*5), "CIAO");
        printf("%zu %s\n", ft_strlen(str), str);
        free(str);
        return(0);
}       
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char *str);

int main(int argc, char **argv)
{
        printf("%zu\n", ft_strlen("CIAO"));
        char *str = malloc(sizeof(char));
        str[0] = ' ';
        str[1] = 'c';
        printf("%d\n", ft_strlen(str));
        return(0);
}       
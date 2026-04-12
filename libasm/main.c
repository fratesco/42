#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(char *s1, char *s2);

int main(int argc, char **argv)
{
        char *str = ft_strcpy(malloc(sizeof(char)*5), "CIAO");
        printf("%zu %s\n", ft_strlen(str), str);
        printf("%d %d\n", ft_strcmp(str, "CIAO!"), strcmp(str, "CIAO!"));
        free(str);
        return(0);
}       
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

size_t ft_strlen(char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(char *s1, char *s2);
size_t ft_write(int fd, const void *buf, size_t count);


int main(int argc, char **argv)
{
        char *str = ft_strcpy(malloc(sizeof(char)*5), "CIAO");
        printf("%zu %s\n", ft_strlen(str), str);
        printf("%d %d\n", ft_strcmp(str, "CIAO!"), strcmp(str, "CIAO!"));
        printf(" ft_write return value = %d, errno = %d", ft_write(987898, str, 10), errno);
        perror(strerror(errno));
        write(987898, str, 10);
        printf("\n write errno %d ", errno);
        perror(strerror(errno));
        free(str);
        return(0);
}       
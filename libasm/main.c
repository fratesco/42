#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(char *s1, char *s2);
size_t ft_write(int fd, const void *buf, size_t count);
size_t ft_read(int fd, void *buf, size_t count);


int main(int argc, char **argv)
{
        char *str = ft_strcpy(malloc(sizeof(char)*5), "CIAO");
        
        printf("\nFT_STRLEN TEST START HERE\n");
        printf("%zu %s\n", ft_strlen(str), str);
        
        printf("\nFT_WRITE TEST START HERE\n");
        printf("%d %d\n", ft_strcmp(str, "CIAO!"), strcmp(str, "CIAO!"));
        
        printf("\nFT_WRITE TEST START HERE\n");
        printf("ft_write return value = %d, errno = %d\n", ft_write(987898, str, 10), errno);
        printf("the call ft_write(987898, str, 10) causes: %s\n", (strerror(errno)));
        write(987898, str, 10);
        printf("write errno %d \n", errno);
        printf("the call write(987898, str, 10) causes: %s\n", (strerror(errno)));
        int readonly = open("test.txt", O_RDONLY);
        int writeonly = open("test.txt", O_WRONLY);
        ft_write(readonly, "TEST", 4);
        printf("ft_write(readonly, \"TEST\", 4) causes: %s\n", (strerror(errno)));

        printf("\nFT_READ TEST START HERE\n");
        char *buf = (char *)malloc(sizeof(char) * 10);
        ft_read(readonly, buf, 10);
        printf("the call ft_write(1, buf, 10) prints: ");
        fflush(stdout);
        ft_write(STDOUT_FILENO, buf, 10);
        ft_write(STDOUT_FILENO, "\n", 1);

        ft_read(writeonly, buf, 10);
        printf("ft_read(writeonly, buf, 10) causes: %s\n", (strerror(errno)));
        ft_read(readonly, 0x0, 15);
        printf("the call ft_read(readonly, 0x0, 15) causes: %s\n", (strerror(errno)));
        
        free(buf);
        free(str);
        close(readonly);
        close(writeonly);
        return(0);
}       
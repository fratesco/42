//commento
#include <stdio.h>
#define CODE "//commento%c#include <stdio.h>%c#define CODE %c%s%c%c#define EXT extern int fprintf(FILE *stream, const char *format, ...);extern FILE *fopen(const char *restrict path, const char *restrict mode);%c#define RUN()int main(void){EXT fprintf(fopen(%cGrace_kid.c%c, %ca%c), CODE, 10, 10, 34, CODE, 34, 10, 10, 34, 34, 34, 34, 10);}%cRUN()"
#define EXT extern int fprintf(FILE *stream, const char *format, ...);extern FILE *fopen(const char *restrict path, const char *restrict mode);
#define RUN()int main(void){EXT fprintf(fopen("Grace_kid.c", "a"), CODE, 10, 10, 34, CODE, 34, 10, 10, 34, 34, 34, 34, 10);}
RUN()
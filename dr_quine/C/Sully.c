#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CODE "#include <stdlib.h>%1$c#include <stdio.h>%1$c#include <string.h>%1$c#define CODE %2$c%4$s%2$c%1$cint main(void)%1$c{%1$cint i = %3$d;%1$cif (i < 0)%1$creturn(0);%1$cchar source[50];%1$cchar exe[50];%1$cchar command[50];%1$csprintf(source, %2$cSully_%%d.c%2$c, i);%1$csprintf(exe, %2$cSully_%%d%2$c, i--);%1$csprintf(command, %2$cclang %%s -o %%s%2$c, source, exe);%1$cFILE *f = fopen(source, %2$cw%2$c);%1$cfprintf(f, CODE, 10, 34, i, CODE);%1$cfclose(f);%1$csystem(command);%1$csprintf(command, %2$c./%%s%2$c, exe);%1$csystem(command);%1$creturn(0);%1$c}"
int main(void)
{
int i = 5;
if (i < 0)
return(0);
char source[50];
char exe[50];
char command[50];
sprintf(source, "Sully_%d.c", i);
sprintf(exe, "Sully_%d", i--);
sprintf(command, "clang %s -o %s", source, exe);
FILE *f = fopen(source, "w");
fprintf(f, CODE, 10, 34, i, CODE);
fclose(f);
system(command);
sprintf(command, "./%s", exe);
system(command);
return(0);
}
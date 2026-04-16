default rel
BITS 64
SECTION .rodata
s db "Sully_%d.s",0
o db "Sully_%d",0
assemble db "nasm -f elf64 %s -o %s.o",0
link db "gcc -Werror -Wall -Wextra %s -o %s",0
run db "./%s",0
code db "default rel%1$cBITS 64%1$cSECTION .rodata%1$cs db %2$cSully_%%d.s%2$c,0%1$co db %2$cSully_%%d%2$c,0%1$cassemble db %2$cnasm -f elf64 %%s -o %%s.o%2$c,0%1$clink db %2$cgcc -Werror -Wall -Wextra %%s -o %%s%2$c,0%1$crun db %2$c./%%s%2$c,0%1$ccode db %2$c%s%2$c,0",0
SECTION .data
i dd 5
source times 50 db 0
command times 50 db 0
exe times 50 db 0
SECTION .text
extern dprintf
extern sprintf
extern system
global main
main:
enter 0, 0
cmp dword[i], 0
jle return
lea rdi, [source]
lea rsi, [s]
movzx rdx, dword[i]
xor rax, rax
call sprintf wrt ..plt
lea rdi, [exe]
lea rsi, [o]
movzx rdx, dword[i]
xor rax, rax
call sprintf wrt ..plt
sub dword[i], -1
lea rdi, [command]
lea rsi, [assemble]
lea rdx, [source]
lea rcx, [exe]
xor rax, rax
call sprintf wrt ..plt
lea rdi, [source]
mov rsi, 02
or  rsi, 100o
mov rdx, 666o
mov rax, 2
syscall
push rax
push 0
mov rdi, rax
lea rsi, [code]
mov rdx, 10
mov rcx, 34
movzx r8, dword[i]
lea r9, [code]
xor rax, rax
call dprintf wrt ..plt
pop rdi
pop rdi
mov rax, 3
syscall
lea rdi, [command]
call system wrt ..plt
lea rdi, [command]
lea rsi, [run]
lea rdx, [exe]
call sprintf wrt ..plt
lea rdi, [command]
call system wrt ..plt
return:
leave
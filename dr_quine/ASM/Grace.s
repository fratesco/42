default rel
;comment
%define O_RDWR 02
%define O_CREAT  0100o
%macro begin 0
SECTION .rodata
code db "default rel%1$c;comment%1$cSECTION .rodata%1$ccode db %2$c%3$s%2$c",0
name db "Grace_kid.s"
SECTION .text
global main
extern dprintf
main:
xor rax, rax
lea rdi, [name]
mov rsi, O_RDWR
or  rsi, O_CREAT
mov rdx, 0666o
mov rax, 2
syscall
mov rdi, rax
xor rax, rax
lea rsi, [code]
mov rdx, 10
mov rcx, 34
lea r8, [code]
call dprintf wrt ..plt
mov rax, 3
syscall
ret
%endmacro

begin


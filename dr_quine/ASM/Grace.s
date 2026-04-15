default rel
;comment
%define O_RDWR 02
%define O_CREAT  0100o
%macro begin 0
SECTION .rodata
code db "default rel%1$c;comment%1$c%%define O_RDWR 02%1$c%%define O_CREAT  0100o%1$c%%macro begin 0%1$cSECTION .rodata%1$ccode db %2$c%3$s%2$c,0%1$cname db %2$cGrace_kid.s%2$c,0%1$cSECTION .text%1$cglobal main%1$cextern dprintf%1$cmain:%1$clea rdi, [name]%1$cmov rsi, O_RDWR%1$cor  rsi, O_CREAT%1$cmov rdx, 666o%1$cmov rax, 2%1$csyscall%1$cmov rdi, rax%1$clea rsi, [code]%1$cmov rdx, 10%1$cmov rcx, 34%1$clea r8, [code]%1$cxor rax, rax%1$cpush rdi   %1$ccall dprintf wrt ..plt%1$cmov rax, 3%1$cpop rdi%1$csyscall%1$c%%endmacro%1$cbegin",0
name db "Grace_kid.s",0
SECTION .text
global main
extern dprintf
main:
lea rdi, [name]
mov rsi, O_RDWR
or  rsi, O_CREAT
mov rdx, 666o
mov rax, 2
syscall
mov rdi, rax
lea rsi, [code]
mov rdx, 10
mov rcx, 34
lea r8, [code]
xor rax, rax
push rdi   
call dprintf wrt ..plt
mov rax, 3
pop rdi
syscall
%endmacro
begin
default rel

BITS 64

global ft_write
extern __errno_location

SECTION .text

ft_write:
        ;rdi 1 arg syscall write int fd
        ;rsi 2 arg syscall write const void *buff
        ;rdx 3 arg syscall write size_t count
        mov rax, 1
        syscall
        cmp rax, 0
        js _error
        ret

_error:
        mov ebx, eax
        call __errno_location wrt ..plt ;devo ancora capire cosa fa wrt
        NEG ebx ; la return value della syscall write é negativa quindi dobbiamo negarla perché il rispettivo errno é positivo
        mov [rax], ebx
        mov rax, -1
        ret
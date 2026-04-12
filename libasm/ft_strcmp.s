default rel

BITS 64

global ft_strcmp

SECTION .text

ft_strcmp:

            mov rcx, -1
            ALIGN 8

_loop:
            add rcx, 1
            mov al, [rdi+rcx]
            sub al, [rsi+rcx]
            jz _loop
            movsx rax, al
            ret



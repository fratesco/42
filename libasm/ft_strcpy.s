default rel

BITS 64

global ft_strcpy

SECTION .text

ft_strcpy:
            mov rax, -1
            ALIGN 8


_loop:
            add rax, 1
            mov cl, byte[rsi+rax]
            mov [rdi+rax], cl
            cmp byte[rsi+rax], 0
            jnz _loop
            mov rax, rdi
            ret
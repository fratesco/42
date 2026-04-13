default rel

BITS 64

global ft_strdup
extern malloc
extern ft_strcpy
extern ft_strlen

SECTION .text

ft_strdup:
            ALIGN 8
            push rdi
            call ft_strlen
            mov rdi, rax
            inc rdi
            call malloc wrt ..plt
            mov rdi, rax
            pop rsi
            call ft_strcpy
            ret
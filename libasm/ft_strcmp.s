default rel

BITS 64

global ft_strcmp

SECTION .text

ft_strcmp:

            mov rcx, -1
            xor rax, rax
            ALIGN 8

_loop:
            add rcx, 1
            mov al, [rdi+rcx]
            sub al, [rsi+rcx]
            jz _loop
            jns _return
            add eax, 0xffffff00
_return:
            ret



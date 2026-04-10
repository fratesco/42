





default rel

global ft_strlen


SECTION .text   6 exec

ft_strlen:
        cmp     byte [rdi], 0
        jz      L_002
        mov     eax, 0




ALIGN   8
L_001:  add     rax, 1
        cmp     byte [rdi+rax], 0
        jnz     L_001
        ret


L_002:
        mov     eax, 0
        ret


SECTION .data    noexec


SECTION .bss     noexec



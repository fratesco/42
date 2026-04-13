default rel

BITS 64

global ft_read
extern __errno_location

SECTION .text

ft_read:
        xor rax, rax
        syscall
        cmp rax, 0
        js _error
        ret

_error:
        mov ebx, eax
        call __errno_location wrt ..plt
        NEG ebx
        mov [rax], ebx
        mov rax, -1
        ret

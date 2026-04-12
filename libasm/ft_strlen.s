default rel

BITS 64

global ft_strlen

SECTION .text

ft_strlen:

			mov rax, -1
			ALIGN 8

_loop:
			add rax, 1
			cmp byte[rdi+rax], 0
			jnz _loop
			ret
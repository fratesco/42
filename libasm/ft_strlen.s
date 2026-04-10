default rel

BITS 64

global ft_strlen

SECTION .text

ft_strlen:

			mov rax, 0
			cmp byte[rdi], 0
			jnz _loop
			ret

_loop:
			add rax, 1
			cmp byte[rdi+rax], 0
			jnz _loop
			ret
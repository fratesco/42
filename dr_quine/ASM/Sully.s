default rel
BITS 64
SECTION .rodata
s db "Sully_%d.s",0
o db "Sully_%d",0
assemble db "nasm -f elf64 %1$s -o %2$s.o ; gcc -Werror -Wall -Wextra %2$s.o -o %2$s",0
run db "./%s",0
code db "default rel%1$cBITS 64%1$cSECTION .rodata%1$cs db %2$cSully_%%d.s%2$c,0%1$co db %2$cSully_%%d%2$c,0%1$cassemble db %2$cnasm -f elf64 %%1$s -o %%2$s.o ; gcc -Werror -Wall -Wextra %%2$s.o -o %%2$s%2$c,0%1$crun db %2$c./%%s%2$c,0%1$ccode db %2$c%4$s%2$c,0%1$cSECTION .data%1$ci dd %3$d%1$csource times 50 db 0%1$ccommand times 100 db 0%1$cexe times 50 db 0%1$cSECTION .text%1$cextern dprintf%1$cextern sprintf%1$cextern system%1$cextern strlen%1$cglobal main%1$cmain:%1$center 0, 0%1$ccmp dword[i], 0%1$cjl return%1$clea rdi, [source]%1$clea rsi, [s]%1$cmovzx rdx, dword[i]%1$cxor rax, rax%1$ccall sprintf wrt ..plt%1$clea rdi, [exe]%1$clea rsi, [o]%1$cmovzx rdx, dword[i]%1$cxor rax, rax%1$ccall sprintf wrt ..plt%1$csub dword[i], 1%1$clea rdi, [command]%1$clea rsi, [assemble]%1$clea rdx, [source]%1$clea rcx, [exe]%1$cxor rax, rax%1$ccall sprintf wrt ..plt%1$clea rdi, [source]%1$cmov rsi, 02%1$cor  rsi, 100o%1$cmov rdx, 666o%1$cmov rax, 2%1$csyscall%1$cpush rax%1$cpush 0%1$cmov rdi, rax%1$clea rsi, [code]%1$cmov rdx, 10%1$cmov rcx, 34%1$cmovzx r8, dword[i]%1$clea r9, [code]%1$cxor rax, rax%1$ccall dprintf wrt ..plt%1$cpop rdi%1$cpop rdi%1$cmov rax, 3%1$csyscall%1$clea rdi, [command]%1$ccall system wrt ..plt%1$clea rdi, [source]%1$ccall strlen wrt ..plt%1$clea rdi, [source]%1$cadd rdi, rax%1$csub rdi, 2%1$cmov [rdi], 46%1$cadd rdi, 1%1$cmov [rdi], 111%1$clea rdi, [source]%1$cmov rax, 87%1$csyscall%1$clea rdi, [command]%1$clea rsi, [run]%1$clea rdx, [exe]%1$ccall sprintf wrt ..plt%1$clea rdi, [command]%1$ccall system wrt ..plt%1$creturn:%1$cleave%1$cret",0
SECTION .data
i dd 5
source times 50 db 0
command times 100 db 0
exe times 50 db 0
SECTION .text
extern dprintf
extern sprintf
extern system
extern strlen
global main
main:
enter 0, 0
cmp dword[i], 0
jl return
lea rdi, [source]
lea rsi, [s]
movzx rdx, dword[i]
xor rax, rax
call sprintf wrt ..plt
lea rdi, [exe]
lea rsi, [o]
movzx rdx, dword[i]
xor rax, rax
call sprintf wrt ..plt
sub dword[i], 1
lea rdi, [command]
lea rsi, [assemble]
lea rdx, [source]
lea rcx, [exe]
xor rax, rax
call sprintf wrt ..plt
lea rdi, [source]
mov rsi, 02
or  rsi, 100o
mov rdx, 666o
mov rax, 2
syscall
push rax
push 0
mov rdi, rax
lea rsi, [code]
mov rdx, 10
mov rcx, 34
movzx r8, dword[i]
lea r9, [code]
xor rax, rax
call dprintf wrt ..plt
pop rdi
pop rdi
mov rax, 3
syscall
lea rdi, [command]
call system wrt ..plt
lea rdi, [source]
call strlen wrt ..plt
lea rdi, [source]
add rdi, rax
sub rdi, 2
mov [rdi], 46
add rdi, 1
mov [rdi], 111
lea rdi, [source]
mov rax, 87
syscall
lea rdi, [command]
lea rsi, [run]
lea rdx, [exe]
call sprintf wrt ..plt
lea rdi, [command]
call system wrt ..plt
return:
leave
ret
default rel
global main
extern printf
;outside
SECTION .rodata
code db "default rel%1$cglobal main%1$cextern printf%1$c;outside%1$cSECTION .rodata%1$ccode db %2$c%3$s%2$c,0%1$cSECTION .text%1$cmain:%1$c;inside%1$cxor rax,rax%1$clea rdi, [code]%1$cmov rsi, 10%1$cmov rdx, 34%1$clea rcx, [code]%1$ccall printf wrt ..plt%1$ccall return%1$creturn:%1$cret",0
SECTION .text
main:
;inside
xor rax,rax
lea rdi, [code]
mov rsi, 10
mov rdx, 34
lea rcx, [code]
call printf wrt ..plt
call return
return:
ret
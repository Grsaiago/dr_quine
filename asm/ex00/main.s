global main
extern printf
section .data
string db "global main%cextern printf%csection .data%cstring db %c%s%c, 0%csection .text%cmain:%cpush rbp%cmov rbp,rsp%cxor rax,rax%clea rdi,[rel string]%cmov rsi,10%cmov rdx,10%cmov r8,34%clea r9,[rel string]%cmov ecx, 25; number of times to push a newline char+align stack%cpush_loop:%cpush 10; push the newline char%cloop push_loop; decrement ecx and repeat if ecx != 0%cpush 34%cmov rcx,10%ccall printf wrt ..plt%cmov rsp,rbp%cpop rbp%c; we need this loop because each push would increase the source code, thus increasing the push thus...%cret%c", 0
section .text
main:
push rbp
mov rbp,rsp
xor rax,rax
lea rdi,[rel string]
mov rsi,10
mov rdx,10
mov r8,34
lea r9,[rel string]
mov ecx, 25; number of times to push a newline char+align stack
push_loop:
push 10; push the newline char
loop push_loop; decrement ecx and repeat if ecx != 0
push 34
mov rcx,10
call printf wrt ..plt
mov rsp,rbp
pop rbp
; we need this loop because each push would increase the source code, thus increasing the push thus...
ret

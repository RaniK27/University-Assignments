%macro sys 3
mov rax, %1
mov rdi, %1
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
msg1: db "Factorial: "
len1: equ $- msg1
msg2: db "Please enter the number.", 10, "Number: "
len2: equ $- msg2

section .bss
result: resb 64
num: resb 16

section .text
global _start
_start:
sys 1, msg2, len2
sys 0, num, 16
mov rax, num
add rax, 30
mov rbx, rax
call _fact
label1:
mov rbx, result
sys 1, msg1, len1
sys 1, result, 64
mov rax, 60
mov rdi, 00


_fact:
mul rbx
dec rbx
jnz label1
call _fact
ret

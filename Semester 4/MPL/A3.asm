%macro sys 3
mov rax, %1
mov rdi, %1
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
array: dq 0xF123456789123456, 0xF125748586ABC057, 0xF73289647A8B1234, 0xF56738638837AB41, 0xFE58357678A12345
msg1: db "Largest Number: "
len1: equ $- msg1
cnt: db 0

section .bss
max: resb 0

section .text
global _start
_start:

mov rsi, array
mov rdx, 0
mov cl, 05h

loop1:
mov rax, qword[rsi]
cmp rax, rdx
jbe check

mov rdx, rax

check:
add rsi, 8
dec cl
jnz loop1

mov rsi, max
mov byte[cnt], 0x10
mov rax, rdx

loop2:
rol rax, 4
mov bl, al
and bl, 0x0F
cmp bl, 0x09
jbe check2
add bl, 07H

check2:
add bl, 30H
mov [rsi], bl
inc rsi
dec byte[cnt]
jnz loop2

sys 1, msg1, len1
sys 1, max, 16

mov rax, 60
mov rdi, 00
syscall 

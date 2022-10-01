section .data 
msg1: db "Please enter a string.", 0xA 
len1: equ $- msg1 
msg2: db "The length of the string is: ", 0xA 
len2: equ $- msg2 
cnt: db 0

section .bss 
str: resb 200 
result: resb 200

section .text 
global_start

_start: 
;Ask user to enter string 
mov rax, 1 
mov rdi, 1 
mov rsi, msg1 
mov rdx, len1 
syscall 
;User enters string 
mov rax, 0 
mov rdi, 0 
mov rsi, str 
mov rdx, 200 
syscall 
;Conversion of Hexadecimal to ASCII 
dec rax 
mov byte[cnt], 64 
mov rsi, result 
label1: 
rol rax, 4 
mov bl, al 
and bl, 0x0F 
cmp bl, 0x09 
JBE label2 
add bl, 07H 
label2: 
add bl, 30H 
mov [rsi], bl 
inc rsi 
dec byte[cnt] 
JNZ label1 
;Display length of string 
mov rax, 1 
mov rdi, 1 
mov rsi, msg2 
mov rdx, len2 
syscall 
mov rax, 1 
mov rdi, 1 
mov rsi, result 
mov rdx, 100 
syscall 
mov rax, 60
mov rdi, 0 
syscall
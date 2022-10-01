%macro sys 3
mov rax, %1
mov rdi, %1
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
menu1: db 10, "S.No.   Operation", 10
menu2: db " 1.     Addition", 10
menu3: db " 2.     Subtraction", 10
menu4: db " 3.     Multiplication", 10
menu5: db " 4.     Division", 10
menu6: db " 5.     Exit", 10
menu7: db "Option: "
len1: equ $- menu1
len2: equ $- menu2
len3: equ $- menu3
len4: equ $- menu4
len5: equ $- menu5
len6: equ $- menu6
len7: equ $- menu7
num1: dq 0x02
num2: dq 0x05


section .bss
result: resb 16
choice: resb 4
cnt: resb 16


section .text
global _start
_start:
call _menu
sys 0, choice, 4
cmp byte[choice], 31
je label1
jmp label2
label1:
call _addition
label2:
cmp byte[choice], 32
je label3
jmp label4
label3: 
call _subtraction
label4:
cmp byte[choice], 33
je label5
jmp label6
label5:
call _multiplication
label6:
cmp byte[choice], 34
je label7
jmp label8
label7:
call _division
label8:
cmp byte[choice], 35H
je label9
jmp _start
label9:
mov rax, 60
mov rdi, 0
syscall


global _menu
_menu:
sys 1, menu1, len1
ret

global _addition
_addition:
mov rax, qword[num1]
add rax, qword[num2]
call _HtA
ret

global _subtraction
_subtraction:
mov rax, qword[num2]
sub rax, qword[num1]
call _HtA
ret

global _multiplication
_multiplication:
mov rax, qword[num1]
mov rbx, qword[num2]
mul rbx
push rax
mov rax, rdx
call _HtA
pop rax
call _HtA
ret 

global _division
_division:
xor rdx, rdx
mov rax, qword[num1]
mov rbx, qword[num2]
div rbx
push rdx
call _HtA
pop rdx
mov rax, rdx
call _HtA
ret

global _HtA
_HtA:
mov rsi, result
mov qword[cnt], 16
l1:
ROL rax, 4
MOV bl, al
AND bl, 0x0F
CMP bl, 0x09
JBE l2
ADD bl, 07H
l2:
ADD bl, 30H
MOV [rsi], bl
INC rsi
DEC byte[cnt]
JNZ l1
sys 1, result, 16
ret

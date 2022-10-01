%macro sys 3	
mov rax, %1
mov rdi, %1
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
	array: dq 0xF123456789123456, 0xF125748586ABC057, 0xF73289647A8B1234, 0xF56738638837AB41, 0xFE58357678A12345
	cnt_neg: db 0	
	cnt_pos: db 0	
	msg1: db "Count of Positive Numbers: "
	len1: equ $-msg1
	msg2: db 0xA,"Count of Negative Numbers: "
	len2: equ $-msg2

section .bss
	result: resb 1			

section .text
global _start
_start:
	mov rsi, array
	mov byte[cnt_pos], 0
	mov byte[cnt_neg], 0
	mov cl, 05h

	loop1:
	mov rax, qword[rsi]
	bt rax, 63		
	jc negative
	
	inc byte[cnt_pos]	
	jmp counter		
	
	negative:		
	inc byte[cnt_neg]	
	
	counter:
	add rsi, 8		
	dec cl	
	jnz loop1
	
	mov rsi, result

	mov bl, byte[cnt_pos]
	cmp bl, 09h
	jbe check
	add bl, 0x07

	check:
	add bl, 0x30
	mov [rsi], bl
	inc rsi
	
	mov bl, byte[cnt_neg]
	cmp bl, 0x09
	jbe check2
	add bl, 0x07

	check2:
	add bl, 0x30
	mov [rsi], bl
	
	sys 1, msg1, len1	
	sys 1, result, 1
	sys 1, msg2, len2
	sys 1, result+1, 8
	
	mov rax, 60
	mov rdi, 00
	syscall

section .data
	msg db "Please enter 5 numbers.",10
	len equ $-msg

section .bss
	array resb 85
	cnt resb 1

section .text
	global _start

_start:
	mov rbx, array
	mov byte[cnt], 05h
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, len
	syscall
	L1: mov rax, 0
	mov rdi, 0
	mov rsi, rbx
	mov rdx, 17
	syscall
	add rbx, 17
	dec byte[cnt]
	JNZ L1
	mov rbx, array
	mov byte[cnt], 05h
	L2: mov rax, 1
	mov rdi, 1
	mov rsi, rbx
	syscall
	add rbx, 17
	dec byte[cnt]
	JNZ L2
	mov rax, 60
	mov rdi, 0
	syscall

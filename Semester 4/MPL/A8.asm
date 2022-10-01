%macro sys 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data
	arr1 db 11h,22h,33h,44h,55h
	space db ' '
	line db 10
	msg1: db 'Before Overlapping :',0xA
	len1: equ $-msg1
	msg2: db 'After Overlapping :',0xA
	len2: equ $-msg2
	
section .bss
	address resb 20
	data resb 5
	dig_count resb 2
	count resb 2
	arr2 resb 10

section .text
global _start
_start:
	mov rsi,arr1
	mov rdi,arr2
	xor rcx,rcx
	mov cx,05
	cld  
	
	rep movsb
	 
	sys msg1,len1
	mov byte[count],05
	mov rsi,arr1
	 
	label1: mov rbx ,rsi
	push rsi
	call addition
	sys space,01
	pop rsi
	 
	mov dl,[rsi]
	push rsi
	call display
	sys line,01
	pop rsi
	inc rsi
	dec byte[count]
	jnz label1
	 
	sys msg2,len2
	mov byte[count],05
	mov rsi,arr2
	 
	label3: 
	mov rbx ,rsi
	push rsi
	call addition
	sys space,01
	pop rsi
	 
	mov dl,[rsi]
	push rsi
	call display
	sys line,01
	pop rsi
	inc rsi
	dec byte[count]
	jnz label3
	mov rax,60
	mov rdi,00
	syscall
	
addition:
	mov byte[dig_count],16
	mov rsi,address
	l:
	rol rbx,04
	mov al,bl
	and al,0Fh
	cmp al,09
	jbe l1
	add al,07h
	
	l1:
	add al,30h
	mov [rsi], al  
	
	inc rsi
	dec byte[dig_count]
	jnz l
	mov rax,01
	mov rdi,01
	mov rsi,address
	mov rdx,16
	syscall
	ret
	
display:
	mov byte[dig_count],02
	mov rsi,data 
	label2:
	rol dl,04
	mov al,dl
	and al,0Fh
	cmp al,09
	jbe l2
	add al,07h
	
	l2:
	add al,30h
	mov [rsi], al 
	
	inc rsi
	dec byte[dig_count]
	jnz label2
	mov rax,01
	mov rdi,01
	mov rsi,data
	mov rdx,02
	syscall
	ret

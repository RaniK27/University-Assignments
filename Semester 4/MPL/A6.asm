%macro sys 3
	mov rax, %1
	mov rdi, %1
	mov rsi, %2
	mov rdx, %3
	syscall
%endmacro

section .data
	rmodemsg db 10,"Processor is in Real Mode"
	rmode_len: equ $-rmodemsg

	pmodemsg db 10,"Processor is in Protected Mode"
	pmode_len: equ $-pmodemsg

	gdtmsg db 10,"GDT Contents are: "
	gmsg_len: equ $-gdtmsg

	ldtmsg db 10,"LDT Contents are: "
	lmsg_len:equ $-ldtmsg

	idtmsg db 10,"IDT Contents are: "
	imsg_len:equ $-idtmsg

	trmsg db 10,"Task Register Contents are: "
	tmsg_len: equ $-trmsg

	mswmsg db 10,"Machine Status Word: "
	mmsg_len:equ $-mswmsg

	colmsg db ':'
	nwline db 10

section .bss
	gdt resd 1
	    resw 1
	ldt resw 1
	idt resd 1
	    resw 1
	tr  resw 1
	cr0_data resd 1
	dnum_buff resb 04

section .text
global _start
_start:	
	smsw eax		;Reading CR0. As MSW is 32-bit cannot use RAX register. 
	mov [cr0_data], rax

	bt rax, 1		;Checking PE bit, if 1=Protected Mode, else Real Mode
	jc label1
	sys 1, rmodemsg, rmode_len
	jmp label2

label1:	
	sys 1, pmodemsg, pmode_len

label2:	
	sgdt [gdt]
	sldt [ldt]
	sidt [idt]
	str [tr]
	sys 1, gdtmsg, gmsg_len
	
	mov bx, [gdt + 4]
	call print_val

	mov bx, [gdt+2]
	call print_val

	sys 1, colmsg, 1

	mov bx, [gdt]
	call print_val

	sys 1, ldtmsg, lmsg_len
	mov bx,[ldt]
	call print_val

	sys 1,idtmsg,imsg_len
	
	mov bx,[idt+4]
	call print_val

	mov bx,[idt+2]
	call print_val

	sys 1, colmsg, 1

	mov bx,[idt]
	call print_val

	sys 1,trmsg, tmsg_len
	
	mov bx,[tr]
	call print_val

	sys 1, mswmsg, mmsg_len
	
	mov bx,[cr0_data+2]
	call print_val

	mov bx,[cr0_data]
	call print_val

	sys 1, nwline,1


exit:	mov rax, 60
	mov rdi, 0
	syscall

print_val:
	mov rsi,dnum_buff	;point esi to buffer
	mov rcx,04		;load number of digits to printlay 

HtA:
	rol bx,4		;rotate number left by four bits
	mov dl,bl		;move lower byte in dl
	and dl,0fh		;mask upper digit of byte in dl
	add dl,30h		;add 30h to calculate ASCII code
	cmp dl,39h		;compare with 39h
	jbe HtA2		;if less than 39h skip adding 07 more 
	add dl,07h		;else add 07
HtA2:
	mov [rsi],dl	;store ASCII code in buffer
	inc rsi			;point to next byte
	loop HtA		;decrement the count of digits to printlay
				    ;if not zero jump to repeat

	sys 1,dnum_buff,4	;printlay the number from buffer
	
	ret
	

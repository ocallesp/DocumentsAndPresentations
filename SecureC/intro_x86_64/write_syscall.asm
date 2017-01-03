; /usr/include/x86_64-linux-gnu/asm/unistd_64.h
global _start

section .text

_start:
	; print message
	mov eax, 1
	mov rdi, 1
	mov rsi, message
	mov rdx, length
	syscall

	; exit successfully
	mov eax, 60
	mov rdi, 11
	syscall	

section .data
	message: db "Hello",0xa
	length equ $-message

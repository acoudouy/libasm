section.text:
	global _ft_read

_ft_read:
	mov	rax, 0x03 ; appel systeme read
	syscall
	ret

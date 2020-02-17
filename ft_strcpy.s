section .text
	global _ft_strcpy

_ft_strcpy:
	xor rcx, rcx; #initialisation
	xor rax, rax;
	jmp _start_loop;

_start_loop:
	cmp [rsi + rcx], BYTE 0x0; #check if rcx is null
	je _end_loop; #if yes stop
	mov dl,BYTE [rsi + rcx]; #transfer rsi + rcs into dl, source
	mov [rdi + rcx], dl; #transfer dl into rdi + rcx, destination
	inc rcx;
	jmp _start_loop;

_end_loop:
	mov dl, BYTE 0x0; #dl is null
	mov BYTE [rdi + rcx], dl; #we close the rcx with null
	mov rax, rdi; #the return is the number of byte copied
	ret

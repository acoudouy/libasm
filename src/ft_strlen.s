section.text:
	global _ft_strlen

_ft_strlen:
	xor rax, rax; #same as mov rax, 0 #initialisation
_begin_loop:
	cmp byte [rdi + rax], 0x0; #we compare rdi + rax and NULL
	jz _stop_loop; #if cmp true  ( = 0) then stop loop
	inc rax; #we incremente the result
	jmp _begin_loop
_stop_loop:
	ret

section.text:
	global _ft_list_size

_ft_list_size:
	xor rax, rax;				#init
	cmp rdi, BYTE 0x0;			#if list null
	je end;
	inc rax;					#else ++
	jmp _count_elem;

_count_elem:
	cmp [rdi + 8], BYTE 0x0; 	#if null
	je end;						
	mov rdi,[rdi + 8];			#else move to next elem
	inc rax;					# & ++
	jmp _count_elem;			#loop

end:
	ret;

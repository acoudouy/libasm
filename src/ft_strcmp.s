section.text:
	global _ft_strcmp

_ft_strcmp:
	push rdx ;					 		#save in order to keep it unchanged			
	push rcx ; 
	mov rdx, 0x0 ;
	mov rcx, 0x0 ;
	cmp rdi, 0x0 ;						#check if one is NULL
	jz _is_null ;
	cmp rsi, 0x0 ;
	jz _is_null ;
	_start_cmp:
		cmp [rdi + rcx], byte 0x0 ;		#is the 1st one NULL?
		jz _first_null ;
		cmp [rsi + rcx], byte 0x0 ;
		jz _first_sup ;
		mov dl, byte [rdi + rcx] ;		#need to save in dl for cmp
		cmp dl, byte [rsi + rcx] ;
		jg _first_sup ; 				#com is > 0
		jl _first_inf ; 				#comp is < 0
		inc rcx ; 						#one more step if comp = 0
		jmp _start_cmp ; 				#loop again

_first_null:
	cmp [rsi + rcx], byte 0x0 ;
	jz _equal ; 						#because both null
	jmp _first_inf ; 					#because 2nd not terminated

_is_null:
	cmp rdi, rsi ;
	jg _first_sup ;
	jl _first_inf ;
	jmp _equal ;

_first_inf:
	pop rdx ;
	pop rcx ;
	mov rax, -1 ;
	ret

_first_sup:
	pop rdx ;
	pop rcx ;
	mov rax, 1 ;
	ret

_equal:
	pop rdx ;
	pop rcx ;
	mov rax, 0 ;
	ret

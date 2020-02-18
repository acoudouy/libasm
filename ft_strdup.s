section.text:
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	call _ft_strlen ; 			#nbchar to malloc
	inc rax ; 					#add \0
	push rdi ; 					#save rdi
	mov rdi, rax ;
	call _malloc ; 				#malloc rax char
	cmp rax, 0x0 ; 				#check if malloc did ok
	jz _return_error ; 			#is not call error
	pop rdi ; 					#take rdi back
	push rsi ; 					#save rsi
	mov rsi, rdi ;
	mov rdi, rax ;				# ???
	call _ft_strcpy ;
	pop rsi ;
	ret

_return_error:
	mov rax, 0x0
	ret

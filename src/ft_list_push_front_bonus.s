section.text:
	global _ft_list_push_front:
	extern _malloc

_ft_list_push_front:				;
			push	rsp				; #align stack
			push	rdi				; #save the pointer on the 1st elem of list, **begin_lst
			push	rsi				; #save content
			xor		rax, rax		; #init
			mov		rdi, 16			; #for the size of the malloc, 8 + 8 in t_list
			call	_malloc			; #malloc(16) -> sizeof(t_list)
			pop		rsi
			pop		rdi
			cmp		rax, 0			; #check malloc
			jz		_exit			; #	stop if failure
			mov		[rax], rsi		; #put the content in new.data
			mov		rcx, [rdi]		; #transfer *begin_list
			mov		[rax + 8], rcx	; #new.next = *begin_list
			mov		[rdi], rax		; #place new elem in the beginning
_exit:
			pop		rsp				; #align stack
			ret

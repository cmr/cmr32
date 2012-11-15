; string.s
; Contains: Str_compare, Str_copy, Str_length, Str_trim, Str_ucase

global Str_length

section .text

Str_length:
; Input: pointer to string (on stack)
; Output: length of string (in eax)
	push ebp
	mov ebp, esp

	push edi

	mov edi, [ebp + 12] ; stack parameter 1
	mov eax, 0

.L0:
	cmp byte [edi], 0
	je .done
	inc eax
	inc edi
	jmp .L0

.done:

	pop edi
	pop ebp
	ret

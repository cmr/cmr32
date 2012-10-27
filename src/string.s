; string.s
; Contains: Str_compare, Str_copy, Str_length, Str_trim, Str_ucase

global Str_length

section .text

Str_length:
; Input: pointer to string (on stack)
; Output: length of string (in eax)
	; TODO: figure out a better way to get this off the stack
	; (maybe use [esp+4] or something after pushing edi?)
	pop eax
	push edi
	mov edi, eax
	mov eax, 0

.L0:
	cmp byte [edi], 0
	je .done
	inc eax
	inc edi
	jmp .L0

.done:
	pop edi
	ret

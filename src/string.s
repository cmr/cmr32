; string.s
; Contains: Str_compare, Str_copy, Str_length, Str_trim, Str_ucase

global Str_length
global Str_copy

section .text

Str_length:
; Input: pointer to string (on stack)
; Output: length of string (in eax)
	push ebp
	mov ebp, esp

	push edi

	mov edi, [ebp + 8] ; stack parameter 1
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

	ret 4

Str_copy:
; Input: two pointers to string (on stack)
; Output: none
	push ebp
	mov ebp, esp

	mov esi, [ebp + 8]
	mov edi, [ebp + 12]
.L0:
	mov al, byte [esi]
	mov byte [edi], al
	inc esi
	inc edi

	cmp al, 0
	jne .L0

	pop ebp
	ret 8

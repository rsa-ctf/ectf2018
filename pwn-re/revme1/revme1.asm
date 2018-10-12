section .data

str: db "^XO]`x+u|i/o?D+uDb+niD}*i?,Di(mV(D+cjrt~ymlrf", 0x00

section .text
	global _start

_start:

	mov esi, str

_func: 
	mov bl, byte [esi]
	cmp bl, 0x00
	je print_str
	xor bl, 0x1b
	mov byte [esi], bl
	inc esi
	jmp _func



print_str: 

	mov eax, 0x04
	mov ebx, 0x01
	mov ecx, str
	mov edx, 46
	int 0x80

_exit:
	mov eax, 0x01
	mov ebx, 0x00
	int 0x80




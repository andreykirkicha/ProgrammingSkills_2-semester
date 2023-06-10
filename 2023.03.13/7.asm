%include "st_io.inc"

global _start

section .data

section .bss

section .text

_start:
    mov eax, (5684 / 4 + 357 / 3 + 245 / 5) * 3

    UNSINT eax
    PUTCHAR 0xA
    
    mov eax, 1
    mov ebx, 0
    int 0x80
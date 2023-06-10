%include "../st_io.inc"

global _start

section .data
    
section .bss

section .text

_start:

    mov eax, 1
    mov ebx, 1
    mov ecx, 2

go:
    cmp ecx, 10
    je end
    mov edx, ebx
    add ebx, eax
    mov eax, edx
    add ecx, 1
    jmp go

end:
    UNSINT ebx
    PUTCHAR 0xA
    FINISH
    
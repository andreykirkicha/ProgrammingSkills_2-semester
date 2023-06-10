%include "../st_io.inc"

global _start

section .data
    a dd 1
    b dd 2

section .bss
    c resd 1

section .text

_start:
    mov ebx, abc
    jmp ebx

abc:
    mov eax, [a]
    mov [c], eax
    mov eax, [b]
    add [c], eax

    UNSINT [c]
    PUTCHAR 0xA

    FINISH

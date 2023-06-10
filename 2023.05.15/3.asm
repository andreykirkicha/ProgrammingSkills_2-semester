%include "../st_io.inc"

global _start

section .data
    
section .bss

section .text

_start:
    mov al, 89
    mov bl, 65
    mov cl, 0

    mov edx, 0
right:
    sar bl, 1
    rcr cl, 1
    add edx, 1
    cmp edx, 4
    jne right

    mov edx, 0
bias:
    sar al, 1
    add edx, 1
    cmp edx, 4
    jne bias
    
    mov edx, 0
left:
    sar al, 1
    rcr cl, 1
    add edx, 1
    cmp edx, 4
    jne left

    mov eax, 0
    mov al, cl

    UNSINT eax
    PUTCHAR 0xA

    FINISH

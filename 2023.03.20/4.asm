%include "../st_io.inc"

global _start

section .data
    x db 2
    a db 7

section .bss

section .text

_start:
    mov al, [x]
    imul byte[x]
    mov dx, ax
    mov cl, 10
    imul cl
    add ax, 5
    neg ax
    mov bx, ax
    neg byte[x]
    mov ax, dx
    imul byte[x]
    add ax, bx
    idiv byte[a]
    movsx eax, al
    movsx edx, dx

    SIGNINT eax
    PUTCHAR 0xA

    SIGNINT edx
    PUTCHAR 0xA

    FINISH

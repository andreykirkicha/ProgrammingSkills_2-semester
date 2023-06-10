%include "../st_io.inc"

global _start

section .data    
    a db 3
    b db 2
    c db 1
    d dw 1

section .bss

section .text

_start:
    mov al, [a]
    mov bl, [b]
    mov cl, al
    add cl, bl
    idiv cl
    mov cl, 10
    imul cl
    mov dx, al
    add dx, byte[c]
    

    FINISH

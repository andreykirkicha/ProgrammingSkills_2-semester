%include "../st_io.inc"

global _start

section .data
    s db "tu+tu*ru+tutu*turu-tututu*tu-pidutudu+", 0
    len equ $ - s
    
section .bss

section .text

_start:

    mov ecx, 0
print_1:
    PUTCHAR [s + ecx]
    add ecx, 1
    cmp ecx, len
    jne print_1
    PUTCHAR 0xA



    mov ecx, len
    mov edi, s
    mov al, '*'
    repne scasb
    mov al, '+'
    sub edi, 1
    stosb



    mov ecx, 0
print_2:
    PUTCHAR [s + ecx]
    add ecx, 1
    cmp ecx, len
    jne print_2
    PUTCHAR 0xA
   
    FINISH

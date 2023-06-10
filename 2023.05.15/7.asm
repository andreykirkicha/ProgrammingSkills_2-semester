%include "../st_io.inc"

global _start

section .data
    s1 db "1234567890", 0
    s2 db "1234567890", 0
    
section .bss

section .text

_start:

    mov ecx, 0
print_1:
    PUTCHAR [s1 + ecx]
    inc ecx
    cmp ecx, 9
    jne print_1

    PUTCHAR 0xA

    mov ecx, 0
print_2:
    PUTCHAR [s2 + ecx]
    inc ecx
    cmp ecx, 9
    jne print_2

    PUTCHAR 0xA

    mov esi, s2 + 4
    mov edi, s1 + 2
    mov ecx, 4
    repe movsb

    mov ecx, 0
print_3:
    PUTCHAR [s1 + ecx]
    inc ecx
    cmp ecx, 9
    jne print_3

    PUTCHAR 0xA

    mov ecx, 0
print_4:
    PUTCHAR [s2 + ecx]
    inc ecx
    cmp ecx, 9
    jne print_4

    PUTCHAR 0xA
   
    FINISH

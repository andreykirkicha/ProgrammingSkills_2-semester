%include "../st_io.inc"

global _start

section .data
    a dd 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    b dd 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    
section .bss

section .text

_start:

    mov ecx, 0
print_1:
    UNSINT [a + ecx]
    add ecx, 4
    cmp ecx, 10 * 4
    PRINT " "
    jne print_1
    PUTCHAR 0xA

    mov ecx, 0
print_2:
    UNSINT [b + ecx]
    add ecx, 4
    cmp ecx, 10 * 4
    PRINT " "
    jne print_2
    PUTCHAR 0xA

   
   
   
    mov esi, a + 6 * 4
    mov edi, b + 6 * 4
    mov ecx, 4
    repe movsd




    mov ecx, 0
print_3:
    UNSINT [a + ecx]
    add ecx, 4
    cmp ecx, 10 * 4
    PRINT " "
    jne print_3
    PUTCHAR 0xA

    mov ecx, 0
print_4:
    UNSINT [b + ecx]
    add ecx, 4
    cmp ecx, 10 * 4
    PRINT " "
    jne print_4
    PUTCHAR 0xA
   
    FINISH

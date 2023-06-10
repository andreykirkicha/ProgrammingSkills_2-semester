%include "../st_io.inc"

global _start

section .data
    
section .bss
    a_1 resb 1
    b_1 resd 1

    a_2 resb 1
    b_2 resw 1

section .text

_start:
    movzx eax, byte[a_1]
    mov [b_1], eax

    movsx bx, [a_2]
    mov [b_2], bx

    FINISH

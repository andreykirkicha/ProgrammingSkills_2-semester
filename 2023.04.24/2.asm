%include "../st_io.inc"

global _start

section .data
    a dd 12680, -132640, 1345560, -24015, -2120678
    b dd -3234, 6467, -2486, 1207, 678
    sum dd 0

section .bss
    c resd 5

section .text

_start:
    mov ecx, 0

do:
    mov eax, [a + ecx * 4]
    cdq
    idiv dword[b + ecx * 4]
    mov [c + ecx * 4], edx
    add [sum], edx
    inc ecx
    cmp ecx, 5
    jne do

    mov ecx, 0

print:
    SIGNINT [c + ecx * 4]
    PUTCHAR ' '
    inc ecx
    cmp ecx, 5
    jne print

    PUTCHAR 0xA

    SIGNINT [sum]

    PUTCHAR 0xA

    FINISH

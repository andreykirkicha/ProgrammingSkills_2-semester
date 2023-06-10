%include "../st_io.inc"

global _start

section .data
    
section .bss
    t resd 1
    h resd 1
    m resd 1
    s resd 1

section .text

_start:
    GETUN [t]
    add dword[t], 1
    
    mov eax, [t]
    cdq
    mov ecx, 3600
    idiv ecx
    mov dword[h], eax

    imul ecx
    sub [t], eax

    mov eax, [t]
    cdq
    mov ecx, 60
    idiv ecx
    mov dword[m], eax

    imul ecx
    sub [t], eax

    mov eax, [t]
    cdq
    mov dword[s], eax

    imul ecx
    sub [t], eax

    UNSINT [h]
    PUTCHAR ':'
    UNSINT [m]
    PUTCHAR ':'
    UNSINT [s]
    PUTCHAR 0xA

    FINISH
%include "../st_io.inc"

global _start

section .data
    
section .bss
    result resd 1
    y resd 1

section .text

_start:
    GETSIG eax
    mov dword[result], eax
    mov ecx, 12
    div ecx
    cmp edx, 0
    je zero_r

    mov dword[y], edx

else:
    mov eax, [result]
    sub eax, [y]
    cdq
    
    div ecx

    SIGNINT eax
    PUTCHAR '.'
    SIGNINT [y]
    PUTCHAR 0xA

    FINISH

zero_r:
    mov dword[y], 12
    jmp else

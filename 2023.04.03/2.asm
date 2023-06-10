%include "../st_io.inc"

global _start

section .data
    arr dd 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, 1, -1, -1, -1, 1, 1
    len equ ($ - arr) / 4
    
section .bss
    k resd 1

section .text

_start:
    GETUN [k]
    dec dword[k]

    mov ecx, len
    mov ebx, 0
    mov edx, 0
    mov eax, -1

skip:
    inc eax
    cmp eax, [k]
    loopne skip

go:
    inc eax
    cmp [arr + eax * 4], ebx
    jl sum
    jmp continue

sum:
    add edx, [arr + eax * 4]

continue:
    cmp eax, len
    loopne go

    SIGNINT edx
    PUTCHAR 0xA
    FINISH
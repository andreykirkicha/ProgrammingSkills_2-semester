%include "../st_io.inc"

global _start

section .data
    arr dd 6, 4, 2, 9, 5, 7, 8
    len equ ($ - arr) / 4

section .bss

section .text

_start:
    pushad
    push dword[arr]
    call find_min
    pop dword[arr]
    popad

    FINISH

find_min:
    push ebp
    mov ebp, esp
    sub esp, 4
    sub ebp, 4

    mov ecx, 0
    mov edx, [arr]
    mov [ebp], edx

checking:
    PUTCHAR '0'
    inc ecx
    cmp [arr + ecx * 4], edx
    PUTCHAR '1'
    jl write

continue:
    cmp dword[ecx], len
    jl checking

write:
    mov eax, [arr + ecx * 4]
    mov [ebp], eax
    jmp continue

    SIGNINT [ebp]
    PUTCHAR 0xA

    add ebp, 4
    mov esp, ebp
    pop ebp
    ret
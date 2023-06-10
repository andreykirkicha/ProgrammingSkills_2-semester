global _start

section .data
    xy dd pointer

section .bss
    pointer resd    1
    x       resd    1
    y       resd    1

section .text

_start:
    mov     dword[x],  xy
    mov     dword[xy], y

    mov eax, 1
    mov ebx, 0
    int 0x80
global _start

section .data
    a db '1', '2', '3', 0xA, 0
    la equ $ - a

section .bss

section .text

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, a
    mov edx, la
    int 0x80

    mov al, [a + 2]
    xchg al, [a]
    mov [a + 2], al
    mov al, [a + 1]
    xchg al, [a]
    mov [a + 1], al

    mov eax, 4
    mov ebx, 1
    mov ecx, a
    mov edx, la
    int 0x80
    mov eax, 1
    mov ebx, 0
    int 0x80
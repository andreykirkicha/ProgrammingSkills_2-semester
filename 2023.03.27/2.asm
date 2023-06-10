%include "../st_io.inc"

global _start

section .data
    
section .bss
    z resd 1

section .text

_start:
    mov eax, 30
    jmp eax

30:
    mov eax, 239
    mov [z], eax
    jmp dword[z]

239:
    mov eax, 566
    mov [z], eax
    mov ebx, z
    jmp [ebx]

566:
    FINISH

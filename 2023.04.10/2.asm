%include "../st_io.inc"

global _start

section .data

section .bss

section .text

_start:
    mov eax, 0
    push eax
    
    inc eax
    push eax

    inc eax
    push eax

    inc eax
    push eax

    inc eax
    push 0

    inc eax
    push eax

    inc eax
    push 0

    inc eax
    push 0

    inc eax
    push eax

    inc eax
    push eax

    mov ecx, 10
    mov ebp, esp
    add ebp, 36

print_stack:
    dec ecx
    UNSINT [ebp]
    PUTCHAR '|'
    sub ebp, 4
    jecxz stop
    jmp print_stack
    
stop:
    PUTCHAR 0xA

    mov bl, 0
    mov ecx, 10
    mov ebp, esp
    mov edx, 0

check:
    dec ecx
    jecxz final
    add ebp, 4

    cmp [ebp], edx
    jne check

    inc bl
    jmp check

final:
    mov al, bl
    cbw
    cwde

    UNSINT eax
    PUTCHAR 0xA

    FINISH
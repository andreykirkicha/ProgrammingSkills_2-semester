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
    push eax

    inc eax
    push eax

    inc eax
    push eax

    inc eax
    push eax

    inc eax
    push eax

    inc eax
    push eax

    mov ecx, 10
    mov ebp, esp
    add ebp, 36

print_stack_1:
    dec ecx
    UNSINT [ebp]
    PUTCHAR '|'
    sub ebp, 4
    jecxz stop_1
    jmp print_stack_1
    
stop_1:
    PUTCHAR 0xA

    pop eax

    mov ebp, esp
    xchg [ebp], eax

    push eax

    mov ecx, 10
    mov ebp, esp
    add ebp, 36

print_stack_2:
    dec ecx
    UNSINT [ebp]
    PUTCHAR '|'
    sub ebp, 4
    jecxz stop_2
    jmp print_stack_2
    
stop_2:
    PUTCHAR 0xA

    FINISH
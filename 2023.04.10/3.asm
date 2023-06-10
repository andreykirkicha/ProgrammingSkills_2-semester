%include "../st_io.inc"

global _start

section .data

section .bss
    tmp resd 1

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

print_stack_1:
    dec ecx
    UNSINT [ebp]
    PUTCHAR '|'
    sub ebp, 4
    jecxz stop_1
    jmp print_stack_1
    
stop_1:
    PUTCHAR 0xA

    mov ecx, 10
    mov ebp, esp
    sub ebp, 4
    mov edx, 0

find_zero:
    dec ecx
    jecxz done
    add ebp, 4

    cmp [ebp], edx
    jne find_zero

    mov ebx, 9
    sub ebx, ecx
    add ebx, 1
    mov ebp, esp
    jmp remove_zero

remove_zero:
    push eax

cycle:
    dec ebx
    add ebp, 4
    xchg [ebp], eax
    cmp ebx, edx
    jne cycle

    jmp find_zero

done:
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
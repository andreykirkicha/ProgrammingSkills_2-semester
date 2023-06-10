%include "../st_io.inc"

global _start

section .data

section .bss
    current_dword resd 1

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
    push 1

    inc eax
    push eax

    inc eax
    push eax

    mov ecx, 10
    mov ebp, esp
    add ebp, 36
    mov edx, 0
    mov al, 0

print_stack:
    dec ecx
    UNSINT [ebp]
    PUTCHAR '|'
    sub ebp, 4
    jecxz stop
    jmp print_stack
    
stop:
    PUTCHAR 0xA

    mov ecx, 10
    mov ebp, esp

find_equal:
    PUTCHAR '|'
    dec ecx
    jecxz end
    mov eax, [ebp]
    mov [current_dword], eax
    mov ebx, ecx

cycle:
    PUTCHAR '*'
    dec ebx
    add ebp, 4
    mov eax, current_dword
    cmp dword[ebp], eax
    je is_equal
    cmp ebx, edx
    jne cycle
    jmp find_equal

is_equal:
    mov al, 1

end:
    cbw
    cwde
    UNSINT eax
    PUTCHAR 0xA

    FINISH

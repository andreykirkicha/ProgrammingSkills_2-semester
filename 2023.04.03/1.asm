%include "../st_io.inc"

global _start

section .data
    arr dd 2, 0, 8, 7, 6, 1, 4
    len equ ($ - arr) / 4

section .bss
    min_ind resd 1
    max_ind resd 1

section .text

_start:
    UNSINT [arr]
    UNSINT [arr + 4]
    UNSINT [arr + 8]
    UNSINT [arr + 12]
    UNSINT [arr + 16]
    UNSINT [arr + 20]
    UNSINT [arr + 24]

    PUTCHAR 0xA

    mov eax, 0
    mov dword[min_ind], 0

find_min:
    mov ebx, [min_ind]
    mov edx, [arr + ebx * 4]
    cmp edx, [arr + eax * 4]
    jb change_min

continue_min:
    inc eax
    cmp eax, len
    je next_step

    loop find_min

change_min:
    mov [min_ind], eax
    jmp continue_min



next_step:
    mov eax, 0
    mov dword[max_ind], 0

find_max:
    mov ebx, [max_ind]
    mov edx, [arr + ebx * 4]
    cmp edx, [arr + eax * 4]
    ja change_max

continue_max:
    inc eax
    cmp eax, len
    je change_values

    loop find_max

change_max:
    mov [max_ind], eax
    jmp continue_max



change_values:
    UNSINT [min_ind]
    PUTCHAR 0xA
    UNSINT [max_ind]
    PUTCHAR 0xA

    mov eax, [min_ind]
    mov ebx, [arr + eax * 4]
    mov ecx, [max_ind]
    xchg ebx, [arr + ecx * 4]
    mov [arr + eax * 4], ebx

    UNSINT [arr]
    UNSINT [arr + 4]
    UNSINT [arr + 8]
    UNSINT [arr + 12]
    UNSINT [arr + 16]
    UNSINT [arr + 20]
    UNSINT [arr + 24]

    PUTCHAR 0xA

    FINISH
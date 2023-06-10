%include "../st_io.inc"

global _start

section .data
    a db 1
    b dw 1
    c dd 1
    
section .bss
    tmp_word resd 1
    tmp_dword resq 1

section .text

_start:
    mov bl, 2
    mov al, [a]
    
byte_cycle:
    mov dl, al
    mul bl

    jo overflow_byte

    inc bl
    loop byte_cycle

overflow_byte:
    dec bl
    UNSINT ebx
    PUTCHAR 0xA
    UNSINT edx
    PUTCHAR 0xA

    PUTCHAR 0xA

    mov bx, 2
    mov ax, [b]
    mov dx, 0
    
word_cycle:
    mov word[tmp_word], ax
    mov word[tmp_word + 2], dx
    mul bx

    jo overflow_word

    inc bx
    loop word_cycle

overflow_word:
    dec bx
    UNSINT ebx
    PUTCHAR 0xA
    UNSINT [tmp_word]
    PUTCHAR 0xA

    PUTCHAR 0xA

    mov ebx, 2
    mov eax, [c]
    mov edx, 0
    
dword_cycle:
    mov dword[tmp_dword], eax
    mov dword[tmp_dword + 4], edx
    mul ebx

    jo overflow_dword

    inc ebx
    loop dword_cycle

overflow_dword:
    dec ebx
    UNSINT ebx
    PUTCHAR 0xA
    UNSINT [tmp_dword]
    PUTCHAR 0xA

    FINISH

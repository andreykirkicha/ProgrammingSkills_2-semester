%include "../st_io.inc"

global _start

section .data
    A dw 254
    B dw 250

section .bss

section .text

_start:
    mov al, [A]
    add al, [B]
    mov [A], al

    mov ah, [A + 1]
    adc ah, [B + 1]
    mov [A + 1], ah

    movzx eax, word[A]

    UNSINT eax
    PUTCHAR 0xA

    FINISH

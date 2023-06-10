%include "st_io.inc"

global _start

section .data

section .bss
    output resb 1

section .text

_start:
    PUTCHAR '*'
    PUTCHAR 0xA

    GETCHAR

    PUTCHAR al
    PUTCHAR 0xA

    FINISH
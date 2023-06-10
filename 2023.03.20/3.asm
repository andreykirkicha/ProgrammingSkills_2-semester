%include "../st_io.inc"

global _start

section .data
    x_1 DD -2147483645
    x_2 DD 4294967293

section .bss

section .text

_start:
    MOV AL, [x_1]
    INC AL
    MOV [x_1], AL

    MOV AL, [x_1 + 1]
    INC AL
    MOV [x_1 + 1], AL

    MOV AL, [x_1 + 2]
    INC AL
    MOV [x_1 + 2], AL

    MOV AL, [x_1 + 3]
    INC AL
    MOV [x_1 + 3], AL

    UNSINT [x_1]
    PUTCHAR 0xA
    
    SIGNINT [x_1]
    PUTCHAR 0xA

    FINISH

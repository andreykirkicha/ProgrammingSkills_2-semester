%include "../st_io.inc"

global _start

section .data
    
section .bss

section .text

_start:
    jmp m

end:
    int 0x80

m:
    PUTCHAR '*'
    PUTCHAR '*'
    UNSINT eax
    jmp end
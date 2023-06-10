%include "../st_io.inc"

global _start

section .data
    
section .bss
    a resd 1
    b resd 1

section .text

_start:
    GETUN [a]
    GETUN [b]

    mov eax, [a]
    imul dword[b]

    jo overflow

    PRINT "YES"
    PUTCHAR 0xA

    FINISH

overflow:
    PRINT "NO"
    PUTCHAR 0xA

    FINISH

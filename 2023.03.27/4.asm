%include "../st_io.inc"

global _start

section .data
    
section .bss
    tmp resw 1

section .text

_start:
    GETSIG [tmp]

go:
    mov eax, [tmp]
    mov ecx, 10
    cdq
    div ecx
    cmp edx, 5
    je five

    cmp eax, 0
    je zero
    mov dword[tmp], eax
    jmp go

zero:
    PRINT "NO"
    PUTCHAR 0xA

    FINISH

five:
    PRINT "YES"
    PUTCHAR 0xA

    FINISH
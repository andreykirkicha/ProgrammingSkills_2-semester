%include "../st_io.inc"

global _start

section .data

section .bss
    arr resd 30

section .text

_start:
    mov eax, 3
    mov ebx, 2
    mov ecx, arr
    mov edx, 30
    int 0x80

    mov ecx, 0
    mov eax, 1
    mov ebp, esp

check:
    cmp byte[arr + ecx], '('
    je psh
    cmp byte[arr + ecx], ')'
    je pp
continue:
    inc ecx
    cmp ecx, 30
    jne check
    jmp finish
psh:
    push eax
    jmp continue
pp:
    pop eax
    jmp continue

finish:
    cmp ebp, esp
    jne no
    PRINT "YES"
    PUTCHAR 0xA
    FINISH

no:
    PRINT "NO"
    PUTCHAR 0xA
    FINISH

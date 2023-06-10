%include "../st_io.inc"

global _start

section .data
    src     dd  1, 2, 3, 4, 5
    len     dd  5

section .bss
    dest    resd 5

section .text

_start:
    pushad
    push    src
    push    dword[len]
    call    reverse
    pop     dword[len]
    pop     dword[src]
    popad

    mov ecx, 0

print:
    UNSINT [dest + ecx * 4]
    PUTCHAR ' '
    inc ecx
    cmp ecx, 5
    jne print

    PUTCHAR 0xA
    FINISH

reverse:
    push    ebp
    mov     ebp, esp
    mov     ecx, 0

do:
    push    dword[ebp + 8 + ecx * 4]
    mov     eax, [ebp - 4]
    mov     ebx, 4
    sub     ebx, ecx
    mov     [dest + ebx * 4], eax
    pop     dword[src + ecx * 4]
    inc ecx
    cmp ecx, 5
    jne do

    mov     esp, ebp
    pop     ebp
    ret

%include "../st_io.inc"

global _start

section .data
    a dd 1
    b dd 2

section .bss
    c resd 1

section .text

_start:
    pushad
    push dword[a]
    push dword[b]
    call plus
    pop dword[a]
    pop dword[b]
    popad

    PUTCHAR 0xA

    pushad
    push dword[a]
    push dword[b]
    call minus
    pop dword[a]
    pop dword[b]
    popad

    FINISH

plus:
    push ebp
    mov ebp, esp
    sub esp, 4

    SIGNINT [ebp]
    PUTCHAR 0xA

    SIGNINT [ebp + 4]
    PUTCHAR 0xA

    SIGNINT [ebp + 8]
    PUTCHAR 0xA

    SIGNINT [ebp + 12]
    PUTCHAR 0xA

    mov edx, [ebp + 8]
    mov ecx, [ebp + 12]

    sub ebp, 4
    mov [ebp], edx

    SIGNINT [ebp]
    PUTCHAR 0xA
    
    add [ebp], ecx

    SIGNINT [ebp]
    PUTCHAR 0xA

    mov eax, [ebp]
    mov [c], eax

    PRINT "answer:  "
    SIGNINT [c]
    PUTCHAR 0xA

    add ebp, 4
    mov esp, ebp
    pop ebp
    ret

minus:
    push ebp
    mov ebp, esp
    sub esp, 4

    SIGNINT [ebp]
    PUTCHAR 0xA

    SIGNINT [ebp + 4]
    PUTCHAR 0xA

    SIGNINT [ebp + 8]
    PUTCHAR 0xA

    SIGNINT [ebp + 12]
    PUTCHAR 0xA

    mov edx, [ebp + 8]
    mov ecx, [ebp + 12]

    sub ebp, 4
    mov [ebp], ecx

    SIGNINT [ebp]
    PUTCHAR 0xA
    
    sub [ebp], edx

    SIGNINT [ebp]
    PUTCHAR 0xA

    mov eax, [ebp]
    mov [c], eax

    PRINT "answer:  "
    SIGNINT [c]
    PUTCHAR 0xA

    add ebp, 4
    mov esp, ebp
    pop ebp
    ret

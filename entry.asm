BITS 32

global _entry
extern c_main

section .text
_entry:
    cli
    cld

    mov esp, 0x90000
    xor ebp, ebp

    call c_main

.hang:
    hlt
    jmp .hang
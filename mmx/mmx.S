.text
.globl _is_mmx_available
_is_mmx_available:
    pushq   %rbx                  
    pushq   %rcx
    pushq   %rdx

    movq    $1, %rax
    cpuid
    movq    %rdx, %rax
    shrq    $23, %rax
    andq    $1, %rax

    popq    %rdx                  
    popq    %rcx
    popq    %rbx
    ret

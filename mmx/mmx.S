.text
.globl _is_mmx_available
_is_mmx_available:
    pushq   %rbx

    movq    $1, %rax
    cpuid
    movq    %rdx, %rax
    shrq    $23, %rax
    andq    $1, %rax

    popq    %rbx                  
    ret

.globl _do_vector_addition
_do_vector_addition:
    pushq %rbp
    movq %rsp, %rbp

    movq %rdi, %mm1
    movq %rsi, %mm2

    paddb %mm2, %mm1

    movq %mm1, %rax
    popq %rbp

    emms
    ret

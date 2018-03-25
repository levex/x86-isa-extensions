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

    # %mm1 = Argument 1
    movq %rdi, %mm1
    # %mm2 = Argument 2
    movq %rsi, %mm2

    # %mm2 = %mm1 + %mm2
    paddd %mm2, %mm1

    # %rax (result register) = %mm2 = %mm1 + %mm2 = arg1 + arg2
    movq %mm1, %rax
    popq %rbp

    # tell the CPU we are done with MMX registers
    emms
    ret

.text
.globl _is_sse_available
_is_sse_available:
    pushq   %rbx

    movq    $1, %rax
    cpuid
    movq    %rdx, %rax
    shrq    $25, %rax
    andq    $1, %rax

    popq    %rbx                  
    ret

.globl _test_sse_addition
_test_sse_addition:
    pushq %rbp
    movq %rsp, %rbp

    movaps (%rsi), %xmm0
    movaps (%rdi), %xmm1
    addps %xmm1, %xmm0

    movaps %xmm0, (%rdx)

    xorq %rax, %rax

    popq %rbp
    ret

.globl _test_sse_max
_test_sse_max:
    pushq %rbp
    movq %rsp, %rbp

    movaps (%rsi), %xmm0
    movaps (%rdi), %xmm1
    maxps %xmm1, %xmm0

    movaps %xmm0, (%rdx)

    xorq %rax, %rax

    popq %rbp
    ret

.globl _test_sse_shuffle
_test_sse_shuffle:
    pushq %rbp
    movq %rsp, %rbp

    movaps (%rsi), %xmm0
    movaps (%rdi), %xmm1

    shufps $0x1b, %xmm1, %xmm0
    movaps %xmm0, (%rdx)

    xorq %rax, %rax

    popq %rbp
    ret

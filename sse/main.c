#include <stdio.h>
#include <stdint.h>

#include <common/color.h>

/* Assembly functions */
extern int is_sse_available(void);
extern int test_sse_addition(volatile float *, volatile float *,
            volatile float *);
extern int test_sse_max(volatile float *, volatile float *,
            volatile float *);
extern int test_sse_shuffle(volatile float *, volatile float *,
            volatile float *);

volatile float a[4] = {3.14f, 2.76f, 2.71f, 8.66f};
volatile float b[4] = {3.14f, 2.12f, 2.11f, 1.22f};
volatile float c[4] = {6.28f, 4.88f, 4.82f, 9.88f};
volatile float d[4] = {3.14f, 2.76f, 2.71f, 8.66f};
volatile float e[4] = {1.22f, 2.11f, 2.76f, 3.14f};
volatile float result[4] = {0.00f, 0.00f, 0.00f, 0.00f};

void
do_examples(void)
{
    printf("     Testing SSE vector addition... ");
    test_sse_addition(a, b, result);
    if (result[0] - c[0] < 0.001f &&
            result[1] - c[1] < 0.001f &&
            result[2] - c[2] < 0.001f &&
            result[3] - c[3] < 0.001f)
        print_correctness(1);
    else {
        print_correctness(0);
        printf("       target[0]: %f [1]: %f [2]: %f [3]: %f\n",
                    c[0], c[1], c[2], c[3]);
        printf("       actual[0]: %f [1]: %f [2]: %f [3]: %f\n",
                    result[0], result[1], result[2], result[3]);
    }

    printf("     Testing SSE vector maxing... ");
    test_sse_max(a, b, result);
    if (result[0] - d[0] < 0.001f &&
            result[1] - d[1] < 0.001f &&
            result[2] - d[2] < 0.001f &&
            result[3] - d[3] < 0.001f)
        print_correctness(1);
    else {
        print_correctness(0);
        printf("       target[0]: %f [1]: %f [2]: %f [3]: %f\n",
                    d[0], d[1], d[2], d[3]);
        printf("       actual[0]: %f [1]: %f [2]: %f [3]: %f\n",
                    result[0], result[1], result[2], result[3]);
    }

    printf("     Testing SSE vector shuffling... ");
    test_sse_shuffle(a, b, result);
    if (result[0] - e[0] < 0.001f && result[0] - e[0] > -0.001f &&
            result[1] - e[1] < 0.001f && result[1] - e[1] > -0.001f &&
            result[2] - e[2] < 0.001f && result[2] - e[2] > -0.001f &&
            result[3] - e[3] < 0.001f && result[3] - e[3] > -0.001f)
        print_correctness(1);
    else {
        print_correctness(0);
        printf("       target[0]: %f [1]: %f [2]: %f [3]: %f\n",
                    e[0], e[1], e[2], e[3]);
        printf("       actual[0]: %f [1]: %f [2]: %f [3]: %f\n",
                    result[0], result[1], result[2], result[3]);
    }
}

int
main(int argc, char **argv)
{
    int avail = 0;

    printf("- Testing for SSE availability... ");
    avail = print_availability(is_sse_available());
    if (avail)
        do_examples();
}

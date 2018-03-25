#include <stdio.h>
#include <stdint.h>

#include <common/color.h>

/* Assembly functions */
extern int is_mmx_available(void);
extern uint32_t do_vector_addition(uint32_t, uint32_t);

void
do_examples(void)
{
    int result;

    printf("     Testing vector addition... ");
    result = do_vector_addition(0x11 << 24 | 0x22 << 16 | 0x33 << 8 | 0x44, 
                                0x00 << 24 | 0x17 << 16 | 0x55 << 8 | 0x11);
    printf("0x%x ", result);
    print_correctness(result == 0x11398855);
}

int
main(int argc, char **argv)
{
    int avail = 0;

    printf("- Testing for MMX availability... ");
    avail = print_availability(is_mmx_available());
    if (avail)
        do_examples();
}

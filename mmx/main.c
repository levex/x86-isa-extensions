#include <stdio.h>

#include <common/color.h>

extern int is_mmx_available(void);

int
main(int argc, char **argv)
{
    printf("Testing for MMX availability... ");
    print_availability(is_mmx_available());
}

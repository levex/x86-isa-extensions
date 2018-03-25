#include <stdio.h>

int
print_availability(int avail)
{
    printf("[%s]\n", avail ? "\e[32;5;196mYES\e[39m" : "\e[38;5;196mNO\e[39m");
    return avail;
}

int
print_correctness(int c)
{
    printf("[%s]\n", c ? "\e[32;5;196mCORRECT\e[39m" : "\e[38;5;196mINCORRECT\e[39m");
    return c;
}

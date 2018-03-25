#include <stdio.h>

void
print_availability(int avail)
{
    printf("[%s]\n", avail ? "\e[32;5;196mYES\e[39m" : "\e[38;5;196mNO\e[39m");
}

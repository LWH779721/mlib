#include <stdio.h>

void hexdump(unsigned char *buffer, int size)
{
    while (size--)
    {
        printf("%02X ", *(buffer++));
    }
    
    printf("\n");
}
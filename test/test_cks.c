#include <mmath.h>
#include <stdio.h>

int main()
{
    uint8_t data[] = {0x13, 0x11, 0x12, 0x23};

    uint16_t cks = checksum(data, sizeof(data)/sizeof(uint8_t));
    
    printf("%u\n", cks);
    return 0;
}
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

uint16_t checksum(uint8_t *data, const size_t size)
{
    uint32_t sum = 0;
    uint16_t *p = (uint16_t *)data;
    int i = 0;

    while (i++ < (size >> 1)){
        sum += *(p++);
    }

    if (size & 0x1){
        sum += *((uint8_t *)p);
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (uint16_t)(~sum);
}
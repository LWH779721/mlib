#include <stdio.h>
#include "mdebug.h"

void hexdump(const unsigned char *buffer, int length)
{
    int count = 0;
    
    while (count < length)
    {
        printf("%02X", buffer[count++]);
        if (count&(DUMPSPERLINE - 1))
        {
            printf(" ");
        } 
        else 
        {
            printf("\n");
        }
    }
  
    if (length&(DUMPSPERLINE - 1))
    {
        printf("\n");
    }
}

void octdump(const unsigned char *buffer, int length)
{
    int count = 0;
    
    while (count < length)
    {
        printf("%02o", buffer[count++]);
        
        if (count&(DUMPSPERLINE - 1))
        {
            printf(" ");
        } 
        else 
        {
            printf("\n");
        }  
    }
    
    if (length&(DUMPSPERLINE - 1))
    {
        printf("\n");
    }
}

void __bitdump(const unsigned char buffer)
{
    unsigned char flag = 0x80;
    
    do 
    {
        (buffer & flag)?printf("1"):printf("0");
        flag >>= 1;
    } while(flag);
}

void bitdump(const unsigned char *buffer, int length)
{
    int count = 0;
    
    while (count < length)
    {
        __bitdump(buffer[count++]);

        if (count&(DUMPSPERLINE - 1))
        {
            printf(" ");
        } 
        else 
        {
            printf("\n");
        }    
    }
    
    if (length&(DUMPSPERLINE - 1))
    {
        printf("\n");
    }
}
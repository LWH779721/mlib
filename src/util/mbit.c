#include <stdio.h>
#include <assert.h>

void mbit_dump(long num, int start, int len)
{
    assert(start >= 0);
    assert(len > 0);
    assert(start + len < (sizeof(num) * 8));
         
    long tmp = 1 << start;
    
    while (len--)
    {
    	printf("%d ", !!(num & tmp));
        tmp <<= 1; 	
    } 

    printf("\n");
}
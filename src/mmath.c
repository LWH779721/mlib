#include <stdio.h>

int mmath_check_same_sign(int a, int b)
{
    if ((a^b) >= 0)
    {
        return 1;
    }
    
    return 0;
}

int mmath_extend_to_pow4(int a)
{
    return (((a + 3) >> 2) << 2);
}
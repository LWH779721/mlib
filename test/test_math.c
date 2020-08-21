#include <stdio.h>
#include <unistd.h>
#include "mdebug.h"

int main()
{
    timer_start();
    
    double a = 1.568 / 0.12 / 4;
    printf("a : %lf\n", a);
    timer_stop();
    
    timer_start();
    
    double a = 1.568 / (0.12 * 4);
    printf("a : %lf\n", a);
    timer_stop();
}
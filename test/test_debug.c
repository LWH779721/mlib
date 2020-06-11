#include <stdio.h>

#include "mdebug.h"

int main(int argc, char **args)
{
	unsigned char buffer[] = {0x01, 0xfe, 0xaf, 0x34};
	
	hexdump(buffer, sizeof(buffer));
    octdump(buffer, sizeof(buffer));
    binarydump(buffer, sizeof(buffer));
    
	return 0;
}
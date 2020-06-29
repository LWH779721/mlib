#include <stdio.h>

#include "mdebug.h"

int main(int argc, char **args)
{
	unsigned char buffer[] = {0x01, 0xfe, 0xaf, 0x34, 0x11, 0x23, 0x33, 0x28, 0xef};
	
	hexdump(buffer, sizeof(buffer));
    octdump(buffer, sizeof(buffer));
    bitdump(buffer, sizeof(buffer));
    
	return 0;
}
#include <stdio.h>

#include "mnet.h"

int main(int argc, char **args)
{
	char ip[20];
	unsigned char mac[20];
	
	get_ip_and_mac("eth0", NULL, mac);
	return 0;
}
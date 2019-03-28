#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int get_ip_and_mac(const char *device, char *ip, unsigned char *mac)
{
	int					sockfd;
	struct sockaddr_in	sin;
	struct ifreq		ifr;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) 
	{
		perror("socket error");
		return -1;
	}
	
	strncpy(ifr.ifr_name, device, IFNAMSIZ);
	
    if (NULL != ip)
	{
		if (ioctl(sockfd, SIOCGIFADDR, &ifr) == 0) 
		{
			memcpy(&sin, &ifr.ifr_addr, sizeof(ifr.ifr_addr));
			printf("ip:  %s\n", inet_ntoa(sin.sin_addr));
			memcpy(ip, inet_ntoa(sin.sin_addr), strlen(inet_ntoa(sin.sin_addr)));
		}	
	}

	if (NULL != mac)
	{
		if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == 0) 
		{	
			memcpy(mac, ifr.ifr_hwaddr.sa_data, 6);
			printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
		}
	}
	
	close(sockfd);
	return 0;
}
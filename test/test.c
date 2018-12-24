#include <stdio.h>
#include "mfile.h"

extern int local_socket_server(const char *fname);
extern int local_socket_server_send(int socket_fd, const char *dst_fname, char *buffer, int len);

int main(int argc, char **args)
{
#if 0    
	int server = local_socket_server("/home/lwh/server");
    local_socket_server_send(server, "/home/lwh/client", "from server", 20);
   
	int client = local_socket_server("/home/lwh/client");
	char buffer[100] = {0};

	local_socket_server_send(server, "/home/lwh/client", "from server", 20);
	local_socket_server_send(client, "/home/lwh/server", "from client", 20);

	
	recv(server, buffer, 100, 0);
	printf("server recv: %s\n", buffer);
	
	recv(client, buffer, 100, 0);
    printf("client recv: %s\n", buffer);
#else
    file_save_less_bytes("a.txt", "MTK8516-6789", strlen("MTK8516-6789"));    
#endif
	return 0;
}

#include <stdio.h>

#include "devices/muart.h"

int main(int argc, char **args)
{
    int uart_fd;
	unsigned char buf[100];
    
    uart_fd = uart_open(args[1]);
	
	uart_set_speed(uart_fd, B115200, 0, 2);
	
	uart_write(uart_fd, "test", 4);
	uart_read(uart_fd, buf, 100);
    
    close(uart_fd);
    
    return 0;
}

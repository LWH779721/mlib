#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>      
#include <sys/types.h>   
#include <sys/stat.h>     
#include <fcntl.h>     
#include <termios.h>     
#include <errno.h>
#include <string.h>

int uart_set_speed(int fd,int speed,int flag)
{
	int   status;
	struct termios   Opt;
	speed_t serial_speed[] = {B1200, B2400, B4800, B9600,  B19200, B38400, B57600, B115200};
	int serial_speed_int[] = {1200, 2400, 4800, 9600,  19200, 38400, 57600, 115200};
	
	if (fd < 0)
		return 0;
	printf("set vlpr uart baudrate to %d\n",serial_speed_int[speed]);

	tcgetattr(fd, &Opt);
	cfmakeraw(&Opt);
	tcflush(fd, TCIOFLUSH);
	cfsetispeed(&Opt, serial_speed[speed]);
	cfsetospeed(&Opt, serial_speed[speed]);
	Opt.c_cflag &= ~PARENB;
	if(flag)
	{
		Opt.c_cflag |= CSTOPB;		//two stop bit
	}
	else
	{
		Opt.c_cflag &= ~CSTOPB;		//one stop bit
	}
	
	Opt.c_cflag &= ~CSIZE;
	Opt.c_cflag |= CS8;			//8 bit a frame
	Opt.c_cflag |= (CLOCAL | CREAD);	//enable receive
	Opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);//disable echo
	Opt.c_oflag &= ~(OCRNL|OPOST);		//OUT
	Opt.c_iflag &= ~(INPCK|ICRNL);		//no parity
	Opt.c_cc[VMIN] = 0;
	Opt.c_cc[VTIME] = 0;
	status = tcsetattr(fd, TCSANOW, &Opt);  	
	if  (status != 0)
	{
		perror("tcsetattr fd1");
	}
	
	return 0;
}

int uart_init(char *uart)
{
    int fd;
	
    fd = open(uart, O_RDWR|O_NOCTTY);
	if (fd < 0)
	{
		printf("open uart fail !\n");
		return -1;
	}
	
    uart_set_speed(fd,7,0);
	
	return fd;
}

int uart_read(int fd)
{
    int i, len;
    char buf[50] = {0};
    
    len = read(fd, buf, sizeof(buf));
    if (len > 0)
    {
        buf[len] = 0;
        printf("%s \n",buf);
    }
    
    return 0;
}

int uart_write(int fd, char *buf, int len)
{ 
    int ret;
    
    ret = write(fd, buf, len);  
}
#if 0
int main(int argc, char **args)
{
    int uart_fd, i = 5;
    
    uart_fd = uart_init(args[1]);
    while(i--)
    {
        uart_write(uart_fd, "test", strlen("test"));
        uart_read(uart_fd);
    }
    
    close(uart_fd);
    
    return 0;
}
#endif
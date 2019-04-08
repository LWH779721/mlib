#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>      
#include <sys/types.h>   
#include <sys/stat.h>     
#include <fcntl.h>     
#include <termios.h>     
#include <errno.h>
#include <string.h>

/*
* speed: B1200, B2400, B4800, B9600,  B19200, B38400, B57600, B115200 ...
* timeout: 单位 100ms
*/
int uart_set_speed(int fd, speed_t speed, int flag, unsigned timeout)
{
	int   status;
	struct termios Opt;
	
	if (fd < 0) return -1;
	
	printf("set uart baudrate to %d\n", speed);

	tcgetattr(fd, &Opt);
	cfmakeraw(&Opt);
	tcflush(fd, TCIOFLUSH);
	cfsetispeed(&Opt, speed);
	cfsetospeed(&Opt, speed);
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
	Opt.c_cc[VMIN] = 1;
	Opt.c_cc[VTIME] = timeout;
	status = tcsetattr(fd, TCSANOW, &Opt);  	
	if (status != 0)
	{
		perror("tcsetattr fd1");
		return -1;
	}
	
	return 0;
}

int uart_open(char *uart)
{
    int fd;
	
    fd = open(uart, O_RDWR|O_NOCTTY);
	if (fd < 0)
	{
		printf("open uart fail !\n");
		return -1;
	}
	
	return fd;
}

int uart_read(int fd, unsigned char *buf, unsigned size)
{
    int res = -1, readed = 0;
    
	while (readed < size)
	{
		res = read(fd, buf + readed, size - readed);
		if (res <= 0)
		{
			continue;
		}
		
		readed += res;
    }
	
    return readed;
}

int uart_write(int fd, unsigned char *buf, unsigned size)
{ 
    int ret;
    
    ret = write(fd, buf, size);  
}

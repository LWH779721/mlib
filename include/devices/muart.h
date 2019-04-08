#ifndef __MUART_H__
#define __MUART_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <termios.h> 
/*
* speed: B1200, B2400, B4800, B9600,  B19200, B38400, B57600, B115200 ...
* timeout: 单位 100ms
*/
extern int uart_set_speed(int fd, speed_t speed, int flag, unsigned timeout);
extern int uart_open(char *uart);
extern int uart_read(int fd, unsigned char *buf, unsigned size);
extern int uart_write(int fd, unsigned char *buf, unsigned size);

#ifdef __cplusplus
}
#endif
#endif

#ifndef __MUART_H__
#define __MUART_H__

#ifdef __cplusplus
extern "C"{
#endif

extern int uart_set_speed(int fd,int speed,int flag);
extern int uart_init(char *uart);
extern int uart_read(int fd);
extern int uart_write(int fd, char *buf, int len);

#ifdef __cplusplus
}
#endif
#endif

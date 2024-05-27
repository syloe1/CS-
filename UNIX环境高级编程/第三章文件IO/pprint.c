//对一个文件描述符开启一个或多个文件状态标志 
#include "../apue.h"
#include "../myerr.h" 
#include <fcntl.h>
void set_fl(int fd, int flags) {
	int val;
	if ((val == fcntl(fd, F_GETFL, 0)) < 0) {
		err_sys("fcntl F_GETFL error");
	}
	val |= flags;
	
	if (fcntl(fd, F_SETFL, val) < 0) {
		err_sys("fcntl F_SETFL error");
	}
}


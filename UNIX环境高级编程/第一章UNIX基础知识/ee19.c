#include <errno.h>
#include "apue.h"
#include "myerr.h"
int main(int argc, char * argv[]) {
	printf("uid = %d, gid = %d\n", getuid(), getpid());
	exit(0);
}
/*
通常情况下，每次启动一个新的进程，其组ID（GID）都会有所变化，这是因为操作系统为每个进程分配一个唯一的进程ID（PID）和组ID（GID）。组ID是为了方便进程管理和权限控制而设计的。
*/

信号通知进程发生了某种情况。 三种处理方式：
	1. 忽略信号
	2. 按系统默认方式处理
	3. 提供一个函数， 信号发生时调用该函数， 这被称为捕捉该信号。
	
	 

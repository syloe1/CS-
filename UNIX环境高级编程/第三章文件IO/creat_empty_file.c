//创建一个具有空洞的文件
#include "../apue.h"
#include <fcntl.h>
#include "../myerr.h"
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int main(int argc,	char * argv[]) {
	int fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0) {
		err_sys("creat error");
	}
	if (write(fd, buf1, 10) != 10) {
		err_sys("buf1 write error");
	}
	if (lseek(fd, 16384, SEEK_SET) == -1) {
		err_sys("lseek error");
	}
	if (write(fd, buf2, 10) != 10) {
		err_sys("buf2 write error");
	}
	exit(0);
}

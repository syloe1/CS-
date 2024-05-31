//打开一个文件， 然后解除它的链接。 
#include "../apue.h" 
#include "../myerr.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
	if (open("a.txt", O_RDWR) < 0) {
		err_sys("open error");
	} 
	if (unlink("a.txt") < 0) {
		err_sys("unlink error");
	}
	printf("fiel unlinked\n");
	sleep(15);
	printf("done\n");
	exit(0);
}

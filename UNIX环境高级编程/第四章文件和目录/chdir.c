#include "../apue.h"
#include "../myerr.h"
#include <unistd.h>
int main(void) {
	if (chdir("/tmp") < 0) {
		err_sys("chdir failed");
	}
	printf("chdir to /tmp successed\n");
	exit(0);
}

#include "../apue.h" 
#include "../myerr.h"
#include <stdio.h>
//getc和putc将标准输入复制到标准输出 
int main(void) {
	int c;
	while ((c = getc(stdin)) != EOF) {
		if (putc(c, stdout) == EOF) {
			err_sys("output error");
		}
	}
	if (ferror(stdin)) {
		err_sys("input error");
	}
	exit(0);
}

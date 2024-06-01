#include "../apue.h"
#include "../myerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXLINE 4096
//fgets��fputs����׼���븴�Ƶ���׼���=
// fgets and fputs to copy standard input to standard output
int main(void) {
    char buf[MAXLINE]; // Added missing semicolon
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            err_sys("output error");
        }
    }
    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}


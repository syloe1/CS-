#include "../apue.h"
#include "../myerr.h"
#include <stdio.h>
#include <unistd.h>

static void charatatime(char *str);

int main(void) {
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }
    exit(0);
}

static void charatatime(char *str) {
    char *ptr;
    int c;
    setbuf(stdout, NULL); /* set unbuffered */
    
    for (ptr = str; (c = *ptr++) != '\0';)
        putc(c, stdout);
}


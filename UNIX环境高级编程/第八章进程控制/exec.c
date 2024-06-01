#include "../apue.h"
#include "../myerr.h"
#include <stdio.h>
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

int main(void) {
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        /* specify pathname, specify environment */
        if (execle("/home/sar/bin/echoall", "echoall", "myarg1",
                    "MYARG2", (char*)0, env_init) < 0)
            err_sys("execle error");
    } else {
        if (waitpid(pid, NULL, 0) < 0)
            err_sys("wait error");
    }
    
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) {
        /* specify filename, inherit environment */
        if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
            err_sys("execlp error");
    }
    
    return 0;
}


//编写一段程序调用fork 并使子进程建立一个新的会话。 验证子进程变成了进程组组长且不再有控制终端 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void err_sys(const char* x) {
    perror(x);
    exit(1);
}

void pr_ids(const char *name) {
    printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, sid = %ld\n",
           name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)getsid(0));
}

int main(void) {
    pid_t pid;

    pr_ids("parent");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) {  // parent
        sleep(5);  // sleep to let child finish
        wait(NULL);  // wait for child to exit
    } else {  // child
        pr_ids("child before setsid");

        if (setsid() < 0) {
            err_sys("setsid error");
        }

        pr_ids("child after setsid");

        // Verify that the child no longer has a controlling terminal
        if (tcgetpgrp(STDIN_FILENO) == -1) {
            printf("Child process has no controlling terminal\n");
        } else {
            printf("Child process still has a controlling terminal\n");
        }

        exit(0);
    }

    return 0;
}


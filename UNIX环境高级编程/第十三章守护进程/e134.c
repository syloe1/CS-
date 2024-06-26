//守护进程重读配置文件的另一种实现 
#include "../myerr.h" 
#include "../apue.h"
#include <syslog.h>
#include <errno.h>

extern int lockfile(int);
extern int already_running(void);
void reread(void);

void sigterm(int signo)
{
    syslog(LOG_INFO, "got SIGTERM; exiting");
    exit(0);
}

void sighup(int signo)
{
    syslog(LOG_INFO, "Re-reading configuration file");
    reread();
}
int main(int argc, char *argv[])
{
    char *cmd;
    struct sigaction sa;

    // 获取命令名
    if ((cmd = strrchr(argv[0], '/')) == NULL)
        cmd = argv[0];
    else
        cmd++;

    // 变成守护进程
    daemonize(cmd);

    // 确保守护进程只有一个副本在运行
    if (already_running()) {
        syslog(LOG_ERR, "daemon already running");
        exit(1);
    }

    // 处理感兴趣的信号
    sa.sa_handler = sigterm; // 假设 sigterm 函数已经在别处定义
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGHUP);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) < 0) {
        syslog(LOG_ERR, "can't catch SIGTERM: %s", strerror(errno));
        exit(1);
    }
    sa.sa_handler = sighup; // 假设 sighup 函数已经在别处定义
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGTERM);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0) {
        syslog(LOG_ERR, "can't catch SIGHUP: %s", strerror(errno));
        exit(1);
    }

    // 继续守护进程的其余部分
    // ...

    exit(0);
}

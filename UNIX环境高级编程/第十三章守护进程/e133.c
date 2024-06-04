#include <pthread.h>
#include <signal.h>
#include <syslog.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// 错误处理函数
void err_quit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    exit(1);
}

void err_exit(int err, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, ": %s\n", strerror(err));
    exit(1);
}

// 守护进程初始化函数
void daemonize(const char *cmd) {
    pid_t pid, sid;
    int fd0, fd1, fd2;

    umask(0);

    // 创建一个新进程
    if ((pid = fork()) < 0) {
        err_quit("%s: can't fork", cmd);
    } else if (pid != 0) {  // 父进程
        exit(0);
    }

    // 创建一个新会话
    if ((sid = setsid()) < 0) {
        err_quit("%s: can't setsid", cmd);
    }

    // 改变工作目录到根目录
    if (chdir("/") < 0) {
        err_quit("%s: can't change directory to /", cmd);
    }

    // 关闭所有文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // 重定向文件描述符0, 1, 2到 /dev/null
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
        err_quit("%s: unexpected file descriptors %d %d %d",
                 cmd, fd0, fd1, fd2);
    }
}

// 检查守护进程是否已经在运行
int already_running(void) {
    // 具体实现可以是使用文件锁等方法，这里简单返回0表示未运行
    return 0;
}

// 重读


#include <pthread.h>
#include <signal.h>
#include <syslog.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// ��������
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

// �ػ����̳�ʼ������
void daemonize(const char *cmd) {
    pid_t pid, sid;
    int fd0, fd1, fd2;

    umask(0);

    // ����һ���½���
    if ((pid = fork()) < 0) {
        err_quit("%s: can't fork", cmd);
    } else if (pid != 0) {  // ������
        exit(0);
    }

    // ����һ���»Ự
    if ((sid = setsid()) < 0) {
        err_quit("%s: can't setsid", cmd);
    }

    // �ı乤��Ŀ¼����Ŀ¼
    if (chdir("/") < 0) {
        err_quit("%s: can't change directory to /", cmd);
    }

    // �ر������ļ�������
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // �ض����ļ�������0, 1, 2�� /dev/null
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
        err_quit("%s: unexpected file descriptors %d %d %d",
                 cmd, fd0, fd1, fd2);
    }
}

// ����ػ������Ƿ��Ѿ�������
int already_running(void) {
    // ����ʵ�ֿ�����ʹ���ļ����ȷ���������򵥷���0��ʾδ����
    return 0;
}

// �ض�


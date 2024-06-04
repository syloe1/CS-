//�ػ������ض������ļ�����һ��ʵ�� 
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

    // ��ȡ������
    if ((cmd = strrchr(argv[0], '/')) == NULL)
        cmd = argv[0];
    else
        cmd++;

    // ����ػ�����
    daemonize(cmd);

    // ȷ���ػ�����ֻ��һ������������
    if (already_running()) {
        syslog(LOG_ERR, "daemon already running");
        exit(1);
    }

    // �������Ȥ���ź�
    sa.sa_handler = sigterm; // ���� sigterm �����Ѿ��ڱ𴦶���
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGHUP);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) < 0) {
        syslog(LOG_ERR, "can't catch SIGTERM: %s", strerror(errno));
        exit(1);
    }
    sa.sa_handler = sighup; // ���� sighup �����Ѿ��ڱ𴦶���
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGTERM);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0) {
        syslog(LOG_ERR, "can't catch SIGHUP: %s", strerror(errno));
        exit(1);
    }

    // �����ػ����̵����ಿ��
    // ...

    exit(0);
}

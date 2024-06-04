// �������ʵ��
#include "../myerr.h" // �ٶ� myerr.h ������ err_sys ����
#include "../apue.h"   // �ٶ� apue.h ������ TELL_WAIT, TELL_PARENT, WAIT_PARENT �Ⱥ����
#include <fcntl.h>     // �����ļ�����ѡ���ͷ�ļ�
#include <unistd.h>   // ���� UNIX ��׼�����ͷ�ļ�
#include <stdio.h>    // ������׼��������Ķ���
#include <stdlib.h>   // ������׼�⺯���Ķ���

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) // �����ļ�ģʽ

// �ٶ� writew_lock ��һ�����������ڳ���д������ָ�����ֽ�
extern int writew_lock(int fd, off_t offset, int whence, off_t len);

static void lockabyte(const char *name, int fd, off_t offset) {
    if (writew_lock(fd, offset, SEEK_SET, 1) < 0)
        err_sys("%s: writew_lock error", name);
    printf("%s: got the lock, byte %lld locked\n", name, (long long)offset);
}

int main(void) {
    int fd;
    pid_t pid;

    /* ����һ���ļ���д�������ֽڡ� */
    if ((fd = creat("templock", FILE_MODE)) < 0)
        err_sys("creat error");
    if (write(fd, "ab", 2) != 2)
        err_sys("write error");

    TELL_WAIT();
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid != 0) {
        /* ������ */
        lockabyte("parent", fd, 1);
        TELL_CHILD(pid);
        WAIT_CHILD();
        lockabyte("parent", fd, 0);
    } else {
        /* �ӽ��� */
        lockabyte("child", fd, 0);
        TELL_PARENT(getppid());
        WAIT_PARENT();
        lockabyte("child", fd, 1);
    }

    close(fd); // �ر��ļ�������
    unlink("templock"); // ɾ����ʱ�ļ�
    exit(0);
}

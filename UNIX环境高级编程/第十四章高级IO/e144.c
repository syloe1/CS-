// 死锁检测实例
#include "../myerr.h" // 假定 myerr.h 定义了 err_sys 函数
#include "../apue.h"   // 假定 apue.h 包含了 TELL_WAIT, TELL_PARENT, WAIT_PARENT 等宏或函数
#include <fcntl.h>     // 包含文件控制选项的头文件
#include <unistd.h>   // 包含 UNIX 标准定义和头文件
#include <stdio.h>    // 包含标准输入输出的定义
#include <stdlib.h>   // 包含标准库函数的定义

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) // 定义文件模式

// 假定 writew_lock 是一个函数，用于尝试写入锁定指定的字节
extern int writew_lock(int fd, off_t offset, int whence, off_t len);

static void lockabyte(const char *name, int fd, off_t offset) {
    if (writew_lock(fd, offset, SEEK_SET, 1) < 0)
        err_sys("%s: writew_lock error", name);
    printf("%s: got the lock, byte %lld locked\n", name, (long long)offset);
}

int main(void) {
    int fd;
    pid_t pid;

    /* 创建一个文件并写入两个字节。 */
    if ((fd = creat("templock", FILE_MODE)) < 0)
        err_sys("creat error");
    if (write(fd, "ab", 2) != 2)
        err_sys("write error");

    TELL_WAIT();
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid != 0) {
        /* 父进程 */
        lockabyte("parent", fd, 1);
        TELL_CHILD(pid);
        WAIT_CHILD();
        lockabyte("parent", fd, 0);
    } else {
        /* 子进程 */
        lockabyte("child", fd, 0);
        TELL_PARENT(getppid());
        WAIT_PARENT();
        lockabyte("child", fd, 1);
    }

    close(fd); // 关闭文件描述符
    unlink("templock"); // 删除临时文件
    exit(0);
}

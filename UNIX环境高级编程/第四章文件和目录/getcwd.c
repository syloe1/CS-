#include <stdio.h>     // ���� printf
#include <stdlib.h>    // ���� exit, malloc, free
#include <unistd.h>    // ���� chdir, getcwd
#include <errno.h>     // ���� errno
#include <limits.h>    // ���� PATH_MAX

#include "../apue.h"
#include "../myerr.h"

// ���� path_alloc ����
char *path_alloc(size_t *sizep) {
    char *ptr;
    size_t size;

#ifdef PATH_MAX
    size = PATH_MAX;
#else
    size = 1024;  // ��� PATH_MAX δ���壬ʹ��Ĭ��ֵ
#endif

    if ((ptr = malloc(size)) == NULL) {
        err_sys("malloc error for pathname");
    }

    if (sizep != NULL) {
        *sizep = size;
    }

    return ptr;
}

int main(void) {
    char *ptr;
    size_t size;

    if (chdir("/usr/bin/zstdmt") < 0) {
        err_sys("chdir failed");
    }

    ptr = path_alloc(&size);

    if (getcwd(ptr, size) == NULL) {
        err_sys("getcwd failed");
    }

    printf("cwd = %s\n", ptr);
    free(ptr);  // ȷ���ͷŷ�����ڴ�
    exit(0);
}


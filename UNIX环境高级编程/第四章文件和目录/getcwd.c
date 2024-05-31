#include <stdio.h>     // 包含 printf
#include <stdlib.h>    // 包含 exit, malloc, free
#include <unistd.h>    // 包含 chdir, getcwd
#include <errno.h>     // 包含 errno
#include <limits.h>    // 包含 PATH_MAX

#include "../apue.h"
#include "../myerr.h"

// 定义 path_alloc 函数
char *path_alloc(size_t *sizep) {
    char *ptr;
    size_t size;

#ifdef PATH_MAX
    size = PATH_MAX;
#else
    size = 1024;  // 如果 PATH_MAX 未定义，使用默认值
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
    free(ptr);  // 确保释放分配的内存
    exit(0);
}


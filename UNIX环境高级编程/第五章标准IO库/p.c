//对于IO流打印缓冲状态信息
#include <stdio.h>     // 包含 printf
#include <stdlib.h>    // 包含 exit, malloc, free
#include <unistd.h>    // 包含 chdir, getcwd
#include <errno.h>     // 包含 errno
#include <limits.h>    // 包含 PATH_MAX

#include "../apue.h"
#include "../myerr.h"

void pr_stdio(const char* name, FILE* fp);
int is_unbuffered(FILE* fp);
int is_linebuffered(FILE* fp);
int buffer_size(FILE* fp);

int main(void)  {
    FILE* fp;
    fputs("enter any character\n", stdout);
    if (getchar() == EOF) {
        err_sys("getchar error");
    }
    fputs("one line to standard error\n", stderr);
    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);
    if ((fp = fopen("/etc/passwd", "r")) == NULL) {
        err_sys("fopen error");
    }
    if (getc(fp) == EOF) {
        err_sys("getc error");
    }
    pr_stdio("/etc/passwd", fp);
    fclose(fp);
    exit(0);
}

void pr_stdio(const char* name, FILE* fp) {
    printf("stream = %s, ", name);
    if (is_unbuffered(fp)) {
        printf("unbuffered");
    } else if (is_linebuffered(fp)) {
        printf("line buffered");
    } else {
        printf("fully buffered");
    }
    printf(", buffer size = %d\n", buffer_size(fp));
}

#if defined(_IO_UNBUFFERED)
int is_unbuffered(FILE* fp) {
    return (fp->_flags & _IO_UNBUFFERED);
}
int is_linebuffered(FILE* fp) {
    return (fp->_flags & _IO_LINE_BUF);
}
int buffer_size(FILE* fp) {
    return (fp->_IO_buf_end - fp->_IO_buf_base);
}
#elif defined(__SNBF)
int is_unbuffered(FILE* fp) {
    return (fp->_flags & __SNBF);
}
int is_linebuffered(FILE* fp) {
    return (fp->_flags & __SLBF);
}
int buffer_size(FILE* fp) {
    return (fp->_bf._size);
}
#elif defined(_IONBF)
int is_unbuffered(FILE* fp) {
    return (fp->_flags & _IONBF);
}
int is_linebuffered(FILE* fp) {
    return (fp->_flags & _IOLBF);
}
int buffer_size(FILE* fp) {
    // Not all systems have _base and _ptr, use BUFSIZ as a fallback
    if (fp->_base && fp->_ptr) {
        return (fp->_base - fp->_ptr);
    } else {
        return BUFSIZ; // fallback
    }
}
#else
#error unknown stdio implementation!
#endif


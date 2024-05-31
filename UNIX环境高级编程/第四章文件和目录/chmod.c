//chmodº¯ÊıÊµÀı 
#include "../apue.h" 
#include "../myerr.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;

    // Check if "foo" exists and get its status
    if (stat("foo", &statbuf) < 0) {
        err_sys("stat error for foo");
    }

    // Modify "foo" permissions: remove group execute permission and set the set-group-ID bit
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        err_sys("chmod error for foo");
    }

    // Set "bar" permissions to rw-r--r--
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        err_sys("chmod error for bar");
    }

    exit(0);
}


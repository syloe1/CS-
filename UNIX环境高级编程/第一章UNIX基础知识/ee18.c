#include <errno.h>
#include "apue.h"
#include "myerr.h"
int main(int argc, char * argv[]) {
        fprintf(stderr, "EACCES: %s\n", strerror(EACCES)) ;
        errno = ENOENT;
        perror(argv[0]);
        return 0;
}


#include <stdio.h>
#include <sys/uio.h>
#include <string.h> // °üº¬ memset º¯Êý

const int BUF_SIZE = 100;

int main(int argc, char *argv[]) {
    struct iovec vec[2];
    char buf1[BUF_SIZE];
    char buf2[BUF_SIZE];
    int str_len;

    memset(buf1, 0, BUF_SIZE);
    memset(buf2, 0, BUF_SIZE);

    vec[0].iov_base = buf1;
    vec[0].iov_len = 5;
    vec[1].iov_base = buf2;
    vec[1].iov_len = BUF_SIZE;

    str_len = readv(0, vec, 2);

    printf("Read bytes: %d \n", str_len);
    printf("First message: %s \n", buf1);
    printf("Second message: %s \n", buf2);

    return 0;
}


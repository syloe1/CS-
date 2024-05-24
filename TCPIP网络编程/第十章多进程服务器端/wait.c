#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        return 3;
    } else {
        printf("Child PID: %d\n", pid);
        pid = fork();
        if (pid == 0) {
            exit(7);
        } else {
            printf("Child PID: %d\n", pid); // �����˴���ƴд����
            wait(&status);
            if (WIFEXITED(status)) {   // �����˴���ƴд����
                printf("Child send one: %d\n", WEXITSTATUS(status)); // ����ĩβ�ľ��Ϊ˫����
            }
            wait(&status);
            if (WIFEXITED(status)) {   // �����˴���ƴд����
                printf("Child send two: %d\n", WEXITSTATUS(status)); // ����ĩβ�ľ��Ϊ˫����
            }
            sleep(30);
        }
    }
    return 0;
}


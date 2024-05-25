#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define BUF_SIZE 30

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void read_routine(int sock, char *buf) {
    while (1) {
        int str_len = read(sock, buf, BUF_SIZE - 1);
        if (str_len == 0) {
            return;
        }
        buf[str_len] = 0;
        printf("Message from server: %s", buf);
    }
}

void write_routine(int sock, char* buf) {
    while (1) {
        fgets(buf, BUF_SIZE, stdin);
        if (!strcmp(buf, "q\n") || !strcmp(buf, "Q\n")) {
            shutdown(sock, SHUT_WR);
            return;
        }
        write(sock, buf, strlen(buf));
    }
}

void handle_sigchld(int sig) {
    int status;
    while (waitpid(-1, &status, WNOHANG) > 0);
}

int main(int argc, char* argv[]) {
    int sock;
    pid_t pid;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_adr;

    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
        error_handling("connect() error");
    }

    signal(SIGCHLD, handle_sigchld);  // Set up signal handler to prevent zombie processes

    pid = fork();
    if (pid == -1) {
        error_handling("fork() error");
    }

    if (pid == 0) {
        write_routine(sock, buf);
        exit(0);  // Exit the child process explicitly
    } else {
        read_routine(sock, buf);
        waitpid(pid, NULL, 0);  // Wait for the child process to prevent zombies
    }

    close(sock);
    return 0;
}


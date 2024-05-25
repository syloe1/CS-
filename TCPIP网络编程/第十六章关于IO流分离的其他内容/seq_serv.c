#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

const int BUF_SIZE = 1024;

int main(int argc, char* argv[]) {
    int serv_sock, clnt_sock;
    FILE* readfp;
    FILE* writefp;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    char buf[BUF_SIZE];
    
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        perror("socket() error");
        return 1;
    }

    // Initialize server address structure
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
        perror("bind() error");
        close(serv_sock);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serv_sock, 5) == -1) {
        perror("listen() error");
        close(serv_sock);
        return 1;
    }

    // Accept a connection from a client
    clnt_adr_sz = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
    if (clnt_sock == -1) {
        perror("accept() error");
        close(serv_sock);
        return 1;
    }

    // Create FILE streams for reading and writing
    readfp = fdopen(clnt_sock, "r");
    writefp = fdopen(clnt_sock, "w");
    if (readfp == NULL || writefp == NULL) {
        perror("fdopen() error");
        close(clnt_sock);
        close(serv_sock);
        return 1;
    }

    // Send messages to the client
    fputs("FROM SERVER: Hi~ client ? \n", writefp);
    fputs("I love all of the world \n", writefp);
    fputs("You are awesome \n", writefp);
    fflush(writefp);  // Make sure the messages are sent immediately

    // Close the write stream
    fclose(writefp);

    // Read a message from the client and print it to the standard output
    if (fgets(buf, sizeof(buf), readfp) != NULL) {
        fputs(buf, stdout);
    }

    // Close the read stream and the server socket
    fclose(readfp);
    close(serv_sock);

    return 0;
}


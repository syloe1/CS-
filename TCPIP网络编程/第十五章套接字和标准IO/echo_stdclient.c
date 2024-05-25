#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
const int BUF_SIZE = 1024;
void error_handling(char * message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
int main(int argc, char* argv[]) {
	int sock;
	char message[BUF_SIZE];
	int str_len;
	struct sockaddr_in serv_addr;   //��ַ�ṹ��
	/*
		struct sockaddr_in
		{
			sa_family_t       sin_family;   //��ַ��
			uint16_t          sin_port;     //16λTCP/UDP�˿ں�
			struct in_addr    sin_addr;     //32λIP��ַ
			char			  sin_zero[8] ; //��ʹ��
		}
	*/
	FILE* readfp;
	FILE* writefp;
	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		error_handling("socket() error");
	}
	memset(&serv_addr, 0, sizeof (serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		error_handling("connect() error");
	} else {
		puts("Connected......");
	}
	readfp=fdopen(sock, "r");
	writefp=fdopen(sock, "w");
	while (1) {
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);
		if (!strcmp(message, "q\n") || strcmp(message, "Q\n"))
			break;
		fputs(message, writefp);
		fflush(writefp);
		fgets(message, BUF_SIZE, readfp);
		printf("Message from server: %s", message);
	}
	fclose(writefp);
	fclose(readfp);
	return 0;
}

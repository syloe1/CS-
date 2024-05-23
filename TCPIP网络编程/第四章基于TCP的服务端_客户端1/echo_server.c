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
	int serv_sock, clnt_sock;
	char message[BUF_SIZE];
	int str_len, i;
	struct sockaddr_in serv_adr, clnt_adr;   //地址结构体
	socklen_t clnt_adr_sz;
	/*
		struct sockaddr_in
		{
			sa_family_t       sin_family;   //地址族
			uint16_t          sin_port;     //16位TCP/UDP端口号
			struct in_addr    sin_addr;     //32位IP地址
			char			  sin_zero[8] ; //不使用
		}
	*/
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1) {
		error_handling("socket() error");
	}
	memset(&serv_adr, 0, sizeof (serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));
	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
		error_handling("bind() error");
	}
	if (listen(serv_sock, 5) == -1) {
		error_handling("listen() error");
	}
	clnt_adr_sz=sizeof(clnt_adr);
	for (i = 0; i < 5; i++) {
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		if (clnt_sock == -1) {
			error_handling("accept() error");
		} else {
			printf("Connected client %d \n", i + 1);
		}
		while ((str_len=read(clnt_sock, message, BUF_SIZE)) != 0) {
			write(clnt_sock, message, str_len);
		}
		close(clnt_sock);
	}
	close(serv_sock);
	return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> // ���ͷ�ļ�
const int BUF_SIZE = 3;
int main(int argc, char *argv[]) {
	int fd1, fd2;
	int len;
	char buf[BUF_SIZE];
	// ��Դ�ļ�
	fd1 = open("news.txt", O_RDONLY);
	if (fd1 == -1) {
		perror("Failed to open news.txt");
		return 1;
	}
	// ����Ŀ���ļ������������ض��ļ�
	fd2 = open("cpy.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd2 == -1) {
		perror("Failed to open cpy.txt");
		close(fd1); // �ر�Դ�ļ�������
		return 1;
	}
	// ��ȡԴ�ļ����ݲ�д��Ŀ���ļ�
	while ((len = read(fd1, buf, sizeof(buf))) > 0) {
		write(fd2, buf, len);
	}
	if (len == -1) {
		perror("Error reading from news.txt");
		close(fd1); close(fd2); // �ر��ļ�������
		return 1;
	}
	// �ر��ļ�������
	close(fd1); close(fd2);
	return 0;
}


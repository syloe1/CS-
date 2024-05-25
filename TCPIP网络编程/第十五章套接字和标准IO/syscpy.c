#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> // 添加头文件
const int BUF_SIZE = 3;
int main(int argc, char *argv[]) {
	int fd1, fd2;
	int len;
	char buf[BUF_SIZE];
	// 打开源文件
	fd1 = open("news.txt", O_RDONLY);
	if (fd1 == -1) {
		perror("Failed to open news.txt");
		return 1;
	}
	// 创建目标文件，如果存在则截断文件
	fd2 = open("cpy.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd2 == -1) {
		perror("Failed to open cpy.txt");
		close(fd1); // 关闭源文件描述符
		return 1;
	}
	// 读取源文件内容并写入目标文件
	while ((len = read(fd1, buf, sizeof(buf))) > 0) {
		write(fd2, buf, len);
	}
	if (len == -1) {
		perror("Error reading from news.txt");
		close(fd1); close(fd2); // 关闭文件描述符
		return 1;
	}
	// 关闭文件描述符
	close(fd1); close(fd2);
	return 0;
}


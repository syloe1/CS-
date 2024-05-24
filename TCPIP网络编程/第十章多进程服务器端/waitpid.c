#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char * argv[]) {
	int status;
	pid_t pid = fork();
	if (pid == 0) {
		sleep(15);
		return 24;
	} else {
		while (!waitpid(-1, &status, WNOHANG))  {
			sleep(3);
			puts("sleep 3sec");
		}
		if (WIFEXITED(status)) {   //是正常终止吗
			printf("Child send %d", WEXITSTATUS(status)); //那么返回值是多少
		}
	}
	return 0;
}

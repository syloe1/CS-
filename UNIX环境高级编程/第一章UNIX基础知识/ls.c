#include "apue.h"
#include "myerr.h"          //���ͷ�ļ���Ҫ�Լ��ӽ�ȥ
#include <dirent.h>
 
int main(int argc, char * argv[])
{
	DIR * dp;
	struct dirent *dirp;
	
	if (2 != argc)
	{
		err_quit("usage: ls directory_name");
	}
	if ( NULL == (dp = opendir(argv[1])))
	{
		err_sys("can't open %s", argv[1]);
	}
	
	while (NULL != (dirp = readdir(dp)))
	{
		printf("%s\n", dirp->d_name);
	}
	
	close(dp);
	exit(0);
}

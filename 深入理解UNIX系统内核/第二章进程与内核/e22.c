//fork��exec��ʹ��
if ((result = fork()) == 0)  {
	
} else if (result < 0) {
	perror("fork"); //fork failed
}
//parent continues here

//��������һ���źŴ�����
void sigint_handler(sig)
int sig;
{
	signal(SIGINT, sigint_handler);
	....
}
main() {
	signal (SIGINT, sigint_handler); //install the handler
	...
}

//重新设置一个信号处理函数
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

//û��continuationʱ�� �����̵߳�ʵ��
syscall_l(arg1)  {
	...
	thread_block();
	f2(arg1);
	return ;
}
f2(arg1) {
	...
	return ;
}

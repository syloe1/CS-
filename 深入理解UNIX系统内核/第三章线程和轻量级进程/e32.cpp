//��continuationʱ�� �����̵߳�ʵ�� 
syscall_l(arg1) {
	...
	save arg1 and any other state information
	thread_block(f2);
	//not reached
}
f2() {
	restore arg1 and any other state information
	...
	thread_syscall_return (status);
}

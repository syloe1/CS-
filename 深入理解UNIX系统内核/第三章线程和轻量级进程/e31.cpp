//没有continuation时， 阻塞线程的实现
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

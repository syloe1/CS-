//hello ģ�� 
#include <linux/init.h> 
#include <linux/module.h> 
MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void) {
	printk(KERN_ALERT "Hello, world\n");
	return 0;
} 
static void hello_exit(void) {
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
/*
 Linux�汾�� Centos7 
 	��װ�ں˿������ߺ�ͷ�ļ���
	sudo yum install -y kernel-devel kernel-headers gcc make
 ���ļ�����Ŀ¼дMakefile
 	vi Makefile
 Ȼ��make
 �����ں�ģ�飺insmod hello.ko
 ����ں���Ϣ��dmesg | tail
 ж���ں�ģ�飺 rmmod hello
 ����ں���Ϣ�� dmesg | tail
  
*/ 

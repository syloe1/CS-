//hello 模块 
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
 Linux版本： Centos7 
 	安装内核开发工具和头文件：
	sudo yum install -y kernel-devel kernel-headers gcc make
 在文件所在目录写Makefile
 	vi Makefile
 然后make
 加载内核模块：insmod hello.ko
 检查内核消息：dmesg | tail
 卸载内核模块： rmmod hello
 检查内核消息： dmesg | tail
  
*/ 

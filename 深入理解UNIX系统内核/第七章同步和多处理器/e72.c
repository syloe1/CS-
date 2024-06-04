//用于锁住资源独占使用的信号量
//during initialization
semaphore sem;
initsem(&sem, 1) ;

//on each use
P (&sem);
Use resource;
V (&sem);

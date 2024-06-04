//使用信号量来控制可计数的资源 
/* During initialization */
semaphore counter;
initsem(&counter, resourceCount);

/* Code executed to use the resource */
P(&counter); /* Blocks until resource is available */
Use resource;
/* Guaranteed to be available now */
V(&counter); /* Release the resource */

//ʹ���ź��������ƿɼ�������Դ 
/* During initialization */
semaphore counter;
initsem(&counter, resourceCount);

/* Code executed to use the resource */
P(&counter); /* Blocks until resource is available */
Use resource;
/* Guaranteed to be available now */
V(&counter); /* Release the resource */

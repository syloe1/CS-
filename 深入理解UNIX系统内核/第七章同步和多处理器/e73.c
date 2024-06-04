//使用信号量来等待事件
 /* During initialization */
semaphore event;
initsem(&event, 0); /* probably at boot time */

/* Code executed by thread that must wait on event */
P(&event);
/* Blocks if event has not occurred */

/* Event has occurred */
V(&event);
/* So that another thread may wake up */

/* Continue processing */
/* Code executed when event occurs */
V(&event); /* Wake up one thread */

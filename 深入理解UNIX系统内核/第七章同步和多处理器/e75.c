//自旋锁的实现
void spin_lock(spinlock_t *s)  {
	while(test_and_set(s) != 0) { //already locked
		;//loop until successfuk
	}
}
void spin_unlock(spinlock_t *s) {*s = 0;}

//改良后的自旋锁实现
 void spin_lock(spinlock_t *s)  {
	while(test_and_set(s) != 0) { //already locked
		while (*s != 0) 
			;//loop until successfuk
	}
}
void spin_unlock(spinlock_t *s) {*s = 0;}

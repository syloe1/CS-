//��������ʵ��
void spin_lock(spinlock_t *s)  {
	while(test_and_set(s) != 0) { //already locked
		;//loop until successfuk
	}
}
void spin_unlock(spinlock_t *s) {*s = 0;}

//�������������ʵ��
 void spin_lock(spinlock_t *s)  {
	while(test_and_set(s) != 0) { //already locked
		while (*s != 0) 
			;//loop until successfuk
	}
}
void spin_unlock(spinlock_t *s) {*s = 0;}

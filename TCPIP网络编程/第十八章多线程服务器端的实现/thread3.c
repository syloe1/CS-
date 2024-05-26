#include <stdio.h>
#include <pthread.h>
int sum = 0;
void* thread_summation(void * arg)  {
	int st = ((int*)arg)[0];
	int ed = ((int*)arg)[1];
	while (st <= ed) {
		sum += st;
		st++;
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t id_t1, id_t2;
	int range1[] = {1, 5};
	int range2[] = {6, 10};
	
	pthread_create(&id_t1, NULL, thread_summation, (void*)range1);
	pthread_create(&id_t2, NULL, thread_summation, (void*)range2);
	
	pthread_join(id_t1, NULL);
	pthread_join(id_t2, NULL);
	printf("result: %d \n", sum);
	return 0;
}

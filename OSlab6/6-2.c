# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<unistd.h>
# include<ctype.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<semaphore.h>
# include<sys/sem.h>
//#include <pthread.h> 
//#include <semaphore.h> 
//#include <stdio.h> 
sem_t chopstick[5];
void *thread_func(int no) {
	int i,iteration=5;
	for(i=0; i<iteration; ++i) {
		sem_wait(&chopstick[no]);
		sem_wait(&chopstick[(no+1)%5]);
		sleep(1);
		printf("\nPhilosopher %d : Begin eating",no);
		printf("\nPhilosopher %d : Finish eating\n",no);
		sem_post(&chopstick[no]);
		sem_post(&chopstick[(no+1)%5]);
	}
	pthread_exit(NULL);
}
int main()
{
	int i;
	pthread_t a_thread[5];
	for(i=0; i<5; ++i) {
		sem_init(&chopstick[i],0,0);
		sem_post(&chopstick[i]);
	}
	for(i=0; i<5; ++i) {
		pthread_create(&a_thread[i],NULL,thread_func,(int*) i);
	}
	for(i=0; i<5; ++i) {
		pthread_join(a_thread[i],NULL);
	}
	printf("\n \n thread join succesfull\n");
	exit(0);
}
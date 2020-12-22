#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t writerthreads[1],readerthreads[2];
int readercount = 0;
int counter =0 ;
void *reader(void* param)
{
int i = 0;
	for(;i<500;i++){
		sem_wait(&x);
		readercount++;
		if(readercount==1)
		    sem_wait(&y);
		sem_post(&x);
		printf("reader%d is inside: %d\n", pthread_self() , counter);
		sem_wait(&x);
		readercount--;
		if(readercount==0)
		{
		    sem_post(&y);
		}
		sem_post(&x);
usleep(2);
	}

}

void *writer(void* param)
{
	int i = 0;
	for(;i<500;i++){
		sem_wait(&y);
		counter++;
		printf("Writer%d has entered:%d\n",pthread_self(),counter);

		sem_post(&y);
usleep(2);
	}

}

int main()
{
    sem_init(&x,0,1);
    sem_init(&y,0,1);
	pthread_create(&writerthreads[0],NULL,writer,NULL);
    pthread_create(&readerthreads[0],NULL,reader,NULL);
    pthread_create(&readerthreads[1],NULL,reader,NULL);
    pthread_join(writerthreads[0],NULL);
    pthread_join(readerthreads[0],NULL);
    pthread_join(readerthreads[1],NULL);
}
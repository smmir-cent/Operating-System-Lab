#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int segment_id;
	pid_t pid;
	segment_id =shmget(IPC_PRIVATE , 20*sizeof(char *) , S_IRUSR |S_IWUSR);
	char *str = (char*) shmat(segment_id ,NULL,0); 
	scanf("%s",str);
	printf("Parrent process send : %s\n",str); 
	pid=fork();
	if (pid<0)
	{}
	else if (pid==0)
	{
		printf("child");
		char *dtr = (char*) shmat(segment_id ,NULL,0); 
		printf("Child process recieved : %s\n",dtr); 
	}
	else
	{
		wait(NULL);
		printf("child comlete\n");
		shmctl(segment_id , IPC_RMID  ,NULL);
	}
}

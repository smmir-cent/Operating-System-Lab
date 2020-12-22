#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <time.h>
#include <stdlib.h>
#include <math.h>
void printHistogram(int *hist) {
	int i, j;
	for (i = 0; i < 25; i++) {
		for (j = 0; j < hist[i]/100; j++) {
			printf("*");
		}
		printf("\n");
	}
}



int main() 
{ 
	int fd2[2];  
	char in[100]; 
	int sample ;
	scanf("%d",&sample);
	clock_t begin = clock();
	pipe(fd2); 
	pid_t p = fork(); 
	if (p > 0) 
	{ 
	srand(time(0)); 
	
	int lower = 0, upper = 100; 
	int hist1[25];
	int k = 0;
	for(k=0;k<25;k++){
		hist1[k]=0;
	}
	int counter1 = 0;
	int i , j , num ;
	for(j=0;j<sample/2;j++){
		//printf("%d\n",j);
		counter1=0;
	int temp = rand()%2;
		for(i=0;i<11+temp;i++){
			num = (rand() % (upper - lower + 1)) + lower; 
			if(num>48){
				counter1++;
			}else{
				counter1--;
			}	
		}
		hist1[counter1+12]++;
	}
	wait(NULL);
	int str[25]; 
	close(fd2[1]); 
	read(fd2[0], str, 25*sizeof(int)); 
	for(int i = 0 ;i<25;i++){
		printf("%d ",hist1[i]);
	}
	printf("\n");
	for (i = 0; i < 25; i++) {
		for (j = 0; j < (hist1[i]+str[i])/100; j++) {
			printf("*");
		}
		printf("\n");
	}
	for(int i = 0 ;i<25;i++){
		printf("%d ",hist1[i]+str[i]);
	}
	printf("\n");


	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time = %f\n",time_spent);

	}
	else
	{ 
	//srand(time(0));
	int lower = 0, upper = 100; 
	int hist[25];
	int k = 0;
	for(k=0;k<25;k++){
		hist[k]=0;
	}
	int counter = 0;
	int i , j , num ;
	
	for(j=0;j<sample/2;j++){
		//printf("%d\n",j);
		counter=0;
		int temp = rand()%2;
		for(i=0;i<11+temp;i++){
			num = (rand() % (upper - lower + 1)) + lower; 
			if(num>48){
				counter++;
			}else{
				counter--;
			}
			rand();	
		}
		hist[counter+12]++;
	}
	for(int i = 0 ;i<25;i++){
		printf("%d ",hist[i]);
	}
	printf("\n");
	close(fd2[0]); 
	write(fd2[1], hist, 25*sizeof(int)); 
	exit(0); 
	} 
} 
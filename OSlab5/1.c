#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void printHistogram(int *hist) {
	int i, j;
	for (i = 0; i < 25; i++) {
		for (j = 0; j < hist[i]/100; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main(){
	int sample ;
	scanf("%d",&sample);
	clock_t begin = clock();
	srand(time(0));
	int lower = 0, upper = 100; 
	int hist[25];
	int k = 0;
	for(k=0;k<25;k++){
		hist[k]=0;
	}
	int counter = 0;
	int i , j , num ;

	for(j=0;j<sample;j++){
		//printf("%d\n",j);
		counter=0;
		int temp = rand()%2;
		for(i=0;i<11+temp;i++){
			num = (rand() % 101); 
			if(num>=49){
				counter++;
			}else{
				counter--;
			}	
		}
		//printf("***%d***\n",counter);
		hist[counter+12]++;
	}
	printHistogram(hist);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time = %f\n",time_spent);
for(int i = 0 ;i<25;i++){
		printf("%d ",hist[i]);
	}
	return 0 ;
}



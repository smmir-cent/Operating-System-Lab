#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
int main() 
{ 
	int fd1[2]; 
	int fd2[2];  
	char in[100]; 
	pipe(fd1);
	pipe(fd2); 
	pid_t p = fork(); 
	if (p > 0) 
	{ 
		gets(in); 
		close(fd1[0]);
		write(fd1[1], in, strlen(in)+1); 
		wait(NULL);
		char str[100]; 
		close(fd2[1]); 
		read(fd2[0], str, 100); 
		printf("%s\n", str); 
	}
	else
	{ 
		close(fd1[1]); 
		char str[100]; 
		read(fd1[0], str, 100); 
		int k = strlen(str); 
		int i;
		for (int i=0; i<k; i++)
		{
			//+
			if (str[i]>='A' && str[i]<='Z')
			    str[i] = str[i] + 'a' - 'A';
			else if (str[i]>='a' && str[i]<='z')
			    str[i] = str[i] + 'A' - 'a';
		}
		close(fd2[0]); 
		write(fd2[1], str, strlen(str)+1); 
		exit(0); 
	} 
} 

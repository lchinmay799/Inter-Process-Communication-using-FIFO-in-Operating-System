#define _POSIX SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	if(argc<=1)
		perror("Filename not provided...\n");
	else if(access(argv[1],F_OK)==-1)
	{
		printf("Provided file doesn't exist in this folder...\n");
		return 0;
	}
	else
	{
		int fd=open(argv[1],O_WRONLY,O_TRUNC);
		int i=1;
		char buf[10]="item";
		if(fd==-1)
		{
			printf("Message sending process %d cannot open the file send the message....\n",getpid());
			printf("Project Unsuccessful....\n");
		}
		else
		{
			printf("\t\t\t\t\t Sender Process %d \n\n",getpid());
			while(1)
			{
				sprintf(buf,"%s%c%c%c%d","item",' ','-',' ',i);
				write(fd,buf,sizeof(buf));
				printf("%s is sent...\n",buf);
				i+=1;
				sleep(1);
			}
		}
	}
	return 0;
}
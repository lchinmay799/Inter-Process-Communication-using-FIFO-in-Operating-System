#define _POSIX SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	if(argc<=1)
		perror("Filename not provided....\n");
	else if(access(argv[1],F_OK)==-1)
	{
		printf("Provided file doesn't exist in this folder...\n");
		return 0;
	}
	else
	{
		int fd=open(argv[1],O_RDONLY);
		char buf[10];
		if(fd==-1)
		{
			printf("Receiving process %d cannot open FIFO file to receive the message....\n",getpid());
			printf("Project Unsuccessful......");
		}
		else
		{
			printf("\t\t\t\t\t Receiver Process %d \n\n",getpid());
			while(read(fd,buf,sizeof(buf))>0)
				printf("%s received....\n",buf);
		}
	}
	return 0;
}
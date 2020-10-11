#define _POSIX SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	if(argc<=1)
		perror("Filename not provided....");
	else if(access(argv[1],F_OK)!=-1)
	{
		printf("Provided file already exists in this folder...\n");
		return 0;
	}
	else
	{
		int fd=mkfifo(argv[1],0755);
		if(fd==-1)
		{
			printf("FIFO file %s cannot be created\n",argv[1]);
			printf("Project Unsuccessful....\n");
		}
		else
		{
			printf("FIFO file %s created Successfully...\n",argv[1]);
			printf("You can proceed....\n");
		}
	}
	return 0;
}
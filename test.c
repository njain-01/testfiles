#include<stdio.h>
#include<sys/syscall.h>
#include<errno.h>
#include<unistd.h>
#include<linux/kernel.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv)
{
	printf("Invoking 'processinfo' system call \n\n");
	int pid= atoi(argv[1]);
	long int call=syscall(355, pid, argv[2]);
	FILE *fptr;
	char filename[15];
	strcpy(filename,argv[2]);
	char c;
	if(call == 0)
{
		printf("Executed Succesfully! \n\nProcess Information: \n");
		fptr=fopen(filename,"r");
		c=fgetc(fptr);
		while(c!=EOF)
{
		printf("%c",c);
		c=fgetc(fptr);
}
fclose(fptr);
}
	else
	{
		printf("Error occured while executing \n");
		printf("Error No.: %d\n",errno);
	}

	return 0;
}

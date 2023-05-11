#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid;
	
	printf("my ps id : [%d]\n", getpid());
	printf("my parent ps id : [%d]\n", getppid());
	while(1);
}

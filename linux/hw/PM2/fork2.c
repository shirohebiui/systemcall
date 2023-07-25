#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid;
	pid = fork();
	if(pid == 0) //child ps
	{
		printf("[Child] : Hello, world pid = %d\n", getpid());
	}
	else //paraent ps
	{
		printf("[Parent] : Hello, world pid = %d\n", getpid());
	}
}

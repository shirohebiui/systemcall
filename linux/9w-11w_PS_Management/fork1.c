#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid;
	printf("[%d] start ps\n", getpid());
	pid = fork();
	printf("[%d] ps : return value %d\n", getpid(), pid);
	pid = fork();
	printf("[%d] 222222222222ps : return value %d\n", getpid(), pid);
}

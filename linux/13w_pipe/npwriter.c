#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAXLINE 100

int main()
{
	int fd, length, i;
	char message[MAXLINE];
	sprintf(message, "Hello from PID %d", getpid());
	length = strlen(message)+1;
	do{
		fd = open("myPipe", O_WRONLY); //WRONLY라서 file 없을시 실행안됨
		if (fd == -1) sleep(1); // fd 없으면 기다려
	} while (fd == -1); // fd 생기면 탈출

	for(i=0;i<=3;i++) {
		write(fd, message, length);
		sleep(3);
	}

	close(fd);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAXLINE 256

int main()
{
	int fd1, fd2, n;
	char inmsg[MAXLINE];
	
	fd1 = open("./kms1", O_RDONLY);
	fd2 = open("./kms2", O_WRONLY);
	if(fd1==-1||fd2==-1) //둘중하나라도 open 실패
	{
		perror("open");
		exit(3);
	}
	
	printf("* 클라이언트 시작 \n");
	while(1)
	{
		n = read(fd1, inmsg, MAXLINE); //blocking
		printf("[서버] -> %s\n", inmsg);
		printf("[클라이언트] : ");
		fgets(inmsg, MAXLINE, stdin);
		write(fd2, inmsg, strlen(inmsg)+1);
	}
}


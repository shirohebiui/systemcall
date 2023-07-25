#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXLINE 100

int readLine();

int main()
{
	int fd;
	char str[MAXLINE];
	unlink("myPipe");
	mkfifo("myPipe", 0660);
	fd = open("myPipe", O_RDONLY); 
	while(readLine(fd, str)) 
		printf("%s \n", str);
	close(fd);
	return 0;
}

int readLine(int fd, char *str)
{
	int n;
	do{
		n = read(fd, str, 1); //blocking 상태
				      //wrtier에서 fd close시eof생성
				      //eof만나면 0리턴 -> n=0
	} while(n>0 && *str++ != '\0'); 
	return (n>0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, 0644);
	char buf[512]="apple\n";
	write(fd,buf,512);
	close(fd);
	return 0;
}

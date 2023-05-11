#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char* argv[])
{
	int fd;
	struct student record;
	if(argc<2)
	{
		printf("error\n");
		exit(1);
	}
	if((fd=open(argv[1],O_CREAT|O_TRUNC|O_WRONLY, 0644)) == -1)
	{
		printf("error\n");
		exit(2);
	}
	
	printf("%-9s %-8s %-4s\n","학번", "이름", "점수");
	while((scanf("%d %s %d", &record.id, record.name, &record.score))==3)
	{
		lseek(fd,((record.id)-START_ID)*sizeof(record),SEEK_SET);
		write(fd,(char *)&record,sizeof(record));
	}
	close(fd);
	exit(0);
}











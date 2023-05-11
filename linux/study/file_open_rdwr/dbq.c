#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char* argv[])
{
	int fd;
	int id;
	char c;
	struct student record;
	if(argc<2)
	{
		printf("error\n");
		exit(1);
	}
	if((fd=open(argv[1],O_RDONLY)) == -1)
	{
		printf("error\n");
		exit(2);
	}
	
	do
	{
		printf("학번을 입력하세요\n");
		scanf("%d", &id);
		lseek(fd,((id)-START_ID)*sizeof(record),SEEK_SET);
		read(fd,(char *)&record,sizeof(record));
		if(id == record.id)
			printf("%-9d %-8s %-4d\n", 
				record.id, record.name, record.score);
		else
			printf("존재하지 않는 학번\n");

		printf("continue? Y/N  : ");
		scanf(" %c", &c);
	}while(c=='Y');
	close(fd);
	exit(0);
}











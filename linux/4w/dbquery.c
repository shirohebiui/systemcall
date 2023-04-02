#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student record;
	char c;
	if (argc < 2)
	{
		fprintf(stderr, "Use case: %s file\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1],O_RDONLY)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}
	
//dbquery
	do
	{
		printf("\n Student ID? :");
		if (scanf("%d", &id) == 1)
		{
			lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
			if((read(fd,(char *) &record, sizeof(record))>0) &&
						(record.id != 0))
			printf("name:%s\t ID:%d\t Score:%d\n",
				record.name, record.id, record.score);
			else printf("No Record for %d \n", id);
		}
		else printf("Input error");
		printf("Continue? Y/N");
		scanf(" %c", &c);
	}
	while(c=='Y');	


	close(fd);
	exit(0);
}

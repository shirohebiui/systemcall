#include <stdio.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char* argv[])
{
	FILE *fp;
	struct student rec;
	int id, fd;
	struct flock lock;
	char c='Y';
	fp = fopen(argv[1], "rb");
	fd = open(argv[1], O_RDONLY);

	while(c=='Y')
	{
		printf("\n학번입력:");
		scanf("%d", &id);
		if(fscanf(fp, "%d %s %d", &rec.id, rec.name, &rec.score) == 3)
		{
		lock.l_type = F_RDLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = (id-START_ID)*sizeof(rec);
		lock.l_len=sizeof(rec);
		
		
		fseek(fp, (id-START_ID)*sizeof(rec), SEEK_SET);
		lock.l_type=F_RDLCK;
		fcntl(fd, F_SETLKW, &lock);
		printf("%-9d %-4s %-4d\n", rec.id, rec.name, rec.score);
		lock.l_type= F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		}
		else
			printf("존재하지 않는 학번\n");

		printf("continue? Y/N :");
		scanf("%c", &c);
	}
	
	fclose(fp);
	return 0;
}

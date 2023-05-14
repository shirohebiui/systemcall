#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student rec;
	FILE *fp;
	fp=fopen(argv[1],"r");
	while(fscanf(fp, "%d %s %d", &rec.id, rec.name, &rec.score) == 3)
	{
		printf("%9d %4s %4d\n", rec.id, rec.name, rec.score);
	}
	fclose(fp);
	return 0;
}

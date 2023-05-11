#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student rec;
	FILE *fp;

	fp = fopen(argv[1], "w");
	while( (scanf("%d %s %d", &rec.id, rec.name, &rec.score)) == 3 )
	{
		fprintf(fp, "%d %s %d ", rec.id, rec.name, rec.score);
	}
	fclose(fp);
	return 0;
}

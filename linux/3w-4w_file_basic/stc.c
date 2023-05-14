#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	FILE *fp;
	struct student rec;
	fopen(fp, "wb");
	while(scanf("%d %s %d", &rec.id, rec.name, rec.score) == 3)
	{
		fseek(fp, (rec.id-START_ID)*sizeof(rec), SEEK_SET);
		fprintf(fp, "%d %s %d", rec.id, rec.name, rec.score);
	}
	
	fclose(fp);
	return 0;
}

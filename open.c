#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fp;
    char buf[1024];

	if (fp = fopen(argv[1], "r"))
    {
        fgets(buf, sizeof(buf), fp);
    }
    char *ptr = buf;
    for(int i=0;i<10 && *ptr!=NULL; i++)
    {
        printf("%d %c\n", i, *ptr++);
    }
		
	fclose(fp);
	return 0;
}

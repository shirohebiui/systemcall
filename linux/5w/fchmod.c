#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/* change file access permission */
int main(int argc, char *argv[])
{
	long strtol();
	int newmode;
	newmode = (int)strtol(argv[1], (char**) NULL, 2);
	/* use printf() -> output %o,%x <- newmode  */
	
	printf("o:%o x:%x\n", newmode, newmode);
	if(chmod(argv[2],newmode) == -1)
	{
		perror(argv[2]);
		exit(1);
	}
	exit(0);
}

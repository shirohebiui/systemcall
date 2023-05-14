#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char **ptr;
	extern char **environ;
	int i=0;
	//for(ptr = environ, i=0; ptr[i] != 0; i++)
	//	printf("%s \n", ptr[i]);
	//exit(0);
	for(i=0; environ[i] != 0; i++)
		printf("%s \n", environ[i]);
	exit(0);
}

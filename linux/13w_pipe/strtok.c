#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "ABFAGEFDFDA FGRTAT RTGHHHH";
	printf("ptr:%s\n",str);
	char *ptr = strtok(str, " ");

	printf("ptr:%s\n",str);
	while(ptr != NULL)
	{
		printf("find char: %c, find string :%s\n", *ptr, ptr);
		ptr = strtok(NULL, " ");
	}
	return 0;
}

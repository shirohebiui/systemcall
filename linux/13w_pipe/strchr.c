#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "ABFAGEFDFA FGRTAT RTGHHHH";
	char *ptr = strchr(str, 'G');

	while(ptr != NULL)
	{
		printf("find char: %c, find string :%s\n", *ptr, ptr);
		ptr = strchr(ptr + 1, 'G');
	}
	return 0;
}

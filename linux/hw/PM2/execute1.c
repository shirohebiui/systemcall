#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("부모 프로세스 시작\n");
	if (fork() == 0 )
	{
		execl("/bin/echo", "echo", "hello", NULL);
		//     경로         실행    파라미터
		//                  프로그램
		fprintf(stderr, "첫 번째 실패");
		exit(1);
	}
	printf("부모 프로세스 끝\n");
}

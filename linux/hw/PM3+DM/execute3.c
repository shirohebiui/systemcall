#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*명령줄 인수로 받은 명령을 실행시킨다.*/
int main(int argc, char *argv[])
{
	int child, pid, status;
	pid = fork();
	if (pid == 0 )//자식ps
	{
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "%s:실행 불가\n", argv[1]);
	}
	else //부모ps
	{
		child = wait(&status);
		printf("[%d] 자식 프로세스 %d 종료 \n", getpid(), child);
		printf("\t종료 코드 %d \n", status>>8);
		//printf("\t종료 코드 %x \n", status);
	}
}


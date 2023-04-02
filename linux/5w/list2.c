#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/* 디렉터리 내용을 자세히  리스트한다. */

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);


int main(int argc, char **argv)
{
	DIR *dp;
	char *dir;
	struct dirent *d;
	struct stat st;
	char path[BUFSIZ+1];

	if(argc == 1)
		dir = ".";
	else dir=argv[1];

	if((dp=opendir(dir))==NULL)
		perror(dir);

	while((d=readdir(dp))!=NULL)
	{
		sprintf(path, "%s/%s", dir, d->d_name);
		if(lstat(path,&st)<0)
			perror(path);
		printStat(path, d->d_name, &st);
		printf("\n");
	}
	printf("\n");
	closedir(dp);
	exit(0);
}

void printStat(char *pathname, char *file, struct stat *st)
{
	printf("%5d ", st->st_blocks); //파일의 블록수
	printf("%c%s ", type(st->st_mode), perm(st->st_mode));
       	//-rwxr--r-- , drwxr--r--	
	printf("%3d ", st->st_nlink); //링크수
	printf("%s %s ",getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
	//getpwuid(ID): ID와 일치하는 엔트리를 /etc/passwd 파일에서 찾아서 그 엔트리에 대한 포인터 반환
	//pw_nmae 필드가 사용자 이름을 가지고있다. getgrgid도 비슷하게 동작
	printf("%9d ", st->st_size); //파일 크기
	printf("%.12s ", ctime(&st->st_mtime)+4);
	//ctime : 시간형식 문자열 반환
	printf("%s ", file);
}

/*파일 타입을 리턴*/
//ppt 18p
char type(mode_t mode)
{
	if(S_ISREG(mode))
		return('-');
	if(S_ISDIR(mode))
		return('d');
	if(S_ISCHR(mode))
		return('c');
	if(S_ISBLK(mode))
		return('b');
	if(S_ISLNK(mode))
		return('l');
	if(S_ISFIFO(mode))
		return('p');
	if(S_ISSOCK(mode))
		return('s');
}

/*파일 사용권한을 리턴*/
char* perm(mode_t mode)
{
	int i;
	static char perms[10] = "---------";

	for(i=0;i<3;i++)
	{
		if(mode & (S_IREAD >> i*3)) //S_IREAD : 400(8) = 100 000 000(2)
			perms[i*3]='r';
		if(mode & (S_IWRITE >> i*3)) //S_IWRITE : 200(8) = 010 000 000(2)
			perms[i*3+1]='w';
		if(mode * (S_IEXEC >> i*3))//S_IEXEC : 100(8) = 001 000 000(2)
			perms[i*3+2]='x';
	}
	return(perms);
}

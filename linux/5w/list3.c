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
char* perm(mode_t);
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
	
	long bit = strtol("755",NULL,8);
	printf("%o %o %o", bit&S_IREAD, bit&S_IWRITE,bit& S_IEXEC);
	printf("%o %o %o", bit&(S_IREAD>>3), bit&S_IWRITE,bit& S_IEXEC);
	printf("%o %o %o", bit&S_IREAD, bit&S_IWRITE,bit& S_IEXEC);
	closedir(dp);
	exit(0);
}

void printStat(char *pathname, char *file, struct stat *st)
{
	printf("%c%s ", type(st->st_mode), perm(st->st_mode));
	printf("%ho" , st->st_mode);
       	
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
	else return 0;
}

/*파일 사용권한을 리턴*/
char* perm(mode_t mode)
{
	int i;
	static char perms[10]="---------";
	for(i=0;i<3;i++)
	{
		if(mode & (S_IREAD>>i*3)) //S_IREAD : 400(8) = 100 000 000(2)
			perms[i*3]='r';
		else
			perms[i*3]='-';
		if(mode & (S_IWRITE>>i*3)) //S_IWRITE : 200(8) = 010 000 000(2)
			perms[i*3+1]='w';
		else
			perms[i*3+1]='-';
		if(mode & (S_IEXEC>>i*3))//S_IEXEC : 100(8) = 001 000 000(2)
			perms[i*3+2]='x';
		else
			perms[i*3+2]='-';
	}
	
	return(perms);
}

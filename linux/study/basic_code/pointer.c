#include <stdio.h>

int main()
{
	char A='A';
	char *p=&A;
	char **pp=&p;

	printf("A=%c\n*p=%c\n**pp=%c\n*pp=%s\n", A, *p, **pp, *pp);
	printf("&A=%p\n&p=%p\n&pp=%p\n&*pp=%p\n", &A, &p, &pp, &*pp);
	return 0;
}

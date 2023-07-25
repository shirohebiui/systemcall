#include <stdio.h>

int main(void)
{
	int win;
	int idx;
	int buf[10];

	printf("which index? ");
	scanf("%d", &idx);

	printf("value: ");
	scanf("%d" , &buf[idx]);

	printf("idx: %d, value: %d\n", idx, buf[idx]);
	printf("%p %p\n", &buf[9], &buf[10]);
	//printf("%p\n", &buf[11]); <-error
	if(win == 31337) {
		printf("Theori{----redacted----}");
	}
}

#include <stdio.h>
#include <string.h>

int bin(char x);

int main() {
	unsigned int index=0,dec=0;
	char binary[40];
	printf("input 2binary number(under32)\n");
	scanf("%[01]", binary);
	int tmp=1;
	index = strlen(binary);
	for(int i=index-1;i>=0;i--){
		dec+=bin(binary[i])*tmp;
		tmp*=2;
		printf("%d %d\n",i,tmp);
		
	}

	printf("\n%d\n", dec);
return 0;
}
int bin(char x) {
	if(x=='1') return 1;
	else if(x=='0') return 0;
	return 0;
}

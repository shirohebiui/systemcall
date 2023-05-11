#include <stdio.h>

int main()
{
	unsigned int index = 0, dec =0;
	char binary[40];
	printf("input binary\n");
	scanf("%[01]", binary);
	

	int n=1;
	while(binary[index] != '\0')
	{
		index++;
	}
	
	for(;index>0;index--)
	{
		dec += (binary[index-1] - '0')*n;
		n*=2;
	}
	printf("%d\n", dec);
	return 0;
}

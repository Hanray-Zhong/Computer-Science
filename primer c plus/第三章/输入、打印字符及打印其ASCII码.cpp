#include <stdio.h>
int main(void)
{
	char ch;
	printf("Please enter a character.\n");
	scanf("%c",&ch);
	printf("The cade for %c is %d.",ch,ch);           //要打印ASCII码直接打印 %d 
	return 0;
	
}

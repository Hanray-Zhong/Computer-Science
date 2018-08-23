#include <stdio.h>
int main(void)
{
	int ten=10;
	int two=2;
	
	printf("Doing it right: \n");
	printf("%d minus %d is %d\n",ten,two,ten-two);
	printf("Doing it wrong: \n");
	printf("%d minus %d is %d\n",ten);           //遗漏的参量将为任意值 
	return 0;
}

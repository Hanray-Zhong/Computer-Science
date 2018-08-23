#include <stdio.h>
int main(void)
{
	printf("Please enter your age:");
	int age;
	scanf("%d",&age);
	printf("So your age is %d days.",age*365);
	return 0;
}

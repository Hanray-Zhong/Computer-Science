#include <stdio.h>
int main(void)
{
    int num;
	
	scanf("%d",&num);
	do
		printf("%d",(int)num%10);
	while((num/=10)!=0);
	return 0;
}

#include <stdio.h>
int main(void)
{
	char num[20];
	int i,j;
	i=0;
	while(num[i]=getchar()) 
	{
	    if(num[i]=='\n') break;
		i++;    //读取正整数 
	}
	for(j=i-1;j>=0;j--) 
		printf("%c",num[j]);
	getchar();
	return 0;
}

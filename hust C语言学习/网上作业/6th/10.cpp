#include <stdio.h>
int main(void)
{
	int times,i,j,sum;
	int str[10];
	
	scanf("%d",&times);
	for(i=1;i<=times;i++)
	{
		sum=0;
		for(j=0;j<=9;j++)
		{
			scanf("%d",&str[j]);
			sum+=str[j];
	    }
	    printf("sum=%d\n",sum);
	}
	return 0;
}

#include <stdio.h>
int main(void)
{
	int num[10];
	int i=0,j=0,m=0,sum=0;
	float ave;
	
	while(i<=9)
	{	scanf("%d",&num[i]);
	    i++;
	} 
	for(j;j<=9;j++)
	{
		if(num[j]>0)
		{
			sum=sum+num[j];
			m++;
		}
	}
	ave=sum/m;
	printf("numbers=%d,average=%f",m,ave);
	return 0;
}

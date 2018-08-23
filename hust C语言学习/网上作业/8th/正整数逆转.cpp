#include <stdio.h>
int main(void)
{
	int i,j;
	int num;
	while(1)
	{
		char Num[20];
		scanf("%d",&num);
		if(num==0) break;
		i=0;
		while(num>0)
		{
			Num[i]=num%10+'0';
			num/=10;
			i++;
		}
		for(j=0;j<=i-1;j++) 
		    printf("%c",Num[j]);
		printf("\n");
    }
	return 0;
}

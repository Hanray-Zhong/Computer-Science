#include <stdio.h>
int main(void)
{
	int n,N,i,j,sum;
	
	sum=0;
	i=1;
	
	scanf("%d",&n);
	while(i<=n)
	{
		j=1;
		N=1;
		while(j<=i)
		{
			N=N*i;
			j++;
		}
		sum=sum+N;
		i++;
	}
	printf("%d",sum);
	
	return 0;
}

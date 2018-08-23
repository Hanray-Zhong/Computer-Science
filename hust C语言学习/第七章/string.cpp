#include <stdio.h>
#define N 10
int main(void)
{
	int score[N],sum,i;
	sum=0;
	i=0;
	double average;
	while(i<=N-1)
	{
		scanf("%d",&score[i]);
		i++;
	}
	i=0;
	while(i<=N-1)
	{
		sum+=score[i];
		i++;
	}
	average=1.0*sum/N;                   //保证 average 为浮点数
	printf("sum=%d\n",sum);
	printf("average=%lf",average);
	return 0; 
}

#include<stdio.h>
int main(void)
{
	int N,num,i,x;
	int part_low,part_high,part_mid;
	int mask=~((~0)<<4);
	
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&num);
	    getchar();
		part_low=num&mask;
	    part_high=((num>>12)&mask)<<12;
	    part_mid=num-part_high-part_low;
	    part_low=(part_low<<12);
	    part_high=(part_high>>12)&mask;
	    num=part_high+part_low+part_mid;
	    printf("%d\n",num);
	}
	
	return 0;
}

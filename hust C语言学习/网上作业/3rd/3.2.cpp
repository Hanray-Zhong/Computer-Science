#include<stdio.h>
int main(void)
{
	int N,num,i;
	int part_low,part_high;
	int mask=~((~0)<<8);
	
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&num);
	    getchar();
		part_low=num&mask;
	    part_high=(num>>8)&mask;
	    printf("%c,%c\n",part_high,part_low);
	}
	
	return 0;
}

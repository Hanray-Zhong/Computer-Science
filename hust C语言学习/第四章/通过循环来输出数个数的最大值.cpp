#include <stdio.h>
int main(void)
{
	printf("输出你所输入的数字中最大的一个(以0为结束)\n");
	
	int num,max;
	
	scanf("%d",&num);
	max=num;
	for(;num!=0;)
	{
		scanf("%d",&num);
		max=((max<num||max==num)?num:max);
	}
	printf("max=%d",max);
	return 0;
}

#include <stdio.h>
int main(void)
{
	printf("����������������������һ��(��0Ϊ����)\n");
	
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

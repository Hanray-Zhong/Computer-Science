#include <stdio.h>
int main(void)
{
	unsigned short x,m,n;
	unsigned short mask;
	int times,i;
	scanf("%d",&times);
	for(i=1;i<=times;i++)
	{
	    scanf("%hu %hu %hu",&x,&m,&n);
	    mask=((~0)<<(16-n));           //����mask����ȡ����Ҫ��λ�� 
	    x=(x<<(16-m-n));
	    x=x&mask;                      //��ȡ����Ҫ��λ�� 
	    printf("%hu\n",x);
	}
	return 0;
}

#include <stdio.h>
int main(void)
{
	short x,m,n;
	short mask;
	scanf("%hd %hd %hd",&x,&m,&n);
	printf("\n");
	mask=((~0)<<(16-n));           //����mask����ȡ����Ҫ��λ�� 
	x=(x<<(16-m-n));
	x=x&mask;                      //��ȡ����Ҫ��λ�� 
	printf("%hd",x);
	return 0;
}

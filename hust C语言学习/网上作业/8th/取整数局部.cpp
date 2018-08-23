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
	    mask=((~0)<<(16-n));           //制作mask来截取所需要的位数 
	    x=(x<<(16-m-n));
	    x=x&mask;                      //截取所需要的位数 
	    printf("%hu\n",x);
	}
	return 0;
}

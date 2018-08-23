#include <stdio.h>
int main(void)
{
	short x,m,n;
	short mask;
	scanf("%hd %hd %hd",&x,&m,&n);
	printf("\n");
	mask=((~0)<<(16-n));           //制作mask来截取所需要的位数 
	x=(x<<(16-m-n));
	x=x&mask;                      //截取所需要的位数 
	printf("%hd",x);
	return 0;
}

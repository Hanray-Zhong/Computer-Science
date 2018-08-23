#include<stdio.h>
int main(void)
{
	unsigned long IP;
	short a,b,c,d;
	unsigned long mask;
	
	scanf("%ul",&IP);
	mask=~((~0)<<8);
	a=(IP&mask);
	mask=(mask<<8);
	b=((IP&mask)>>8);
	mask=(mask<<8);
	c=((IP&mask)>>16);
	mask=(mask<<8);
	d=((IP&mask)>>24);
	
	printf("%d.%d.%d.%d",a,b,c,d);
	return 0;
}

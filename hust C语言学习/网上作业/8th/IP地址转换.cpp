#include<stdio.h>
int main(void)
{
	long IP;
	short a,b,c,d;
	long mask;
	int times,i;
	scanf("%d",&times);
	for(i=1;i<=times;i++)
	{
	    scanf("%ld",&IP);
	    mask=~((~0)<<8);
	    a=(IP&mask);
	    mask=(mask<<8);
	    b=((IP&mask)>>8);
	    mask=(mask<<8);
	    c=((IP&mask)>>16);
	    mask=(mask<<8);
	    d=((IP&mask)>>24);
	printf("%d.%d.%d.%d\n",a,b,c,d);
    }
	return 0;
}

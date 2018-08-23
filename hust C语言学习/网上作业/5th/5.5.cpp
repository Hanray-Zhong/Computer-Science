#include <stdio.h>

void Swap(int, int);
int main(void)
{
	int i,a,b;
	i=1;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		printf("Case %d:\nBefore Swap:a=%d b=%d\n",i,a,b);
		Swap(a,b);
	    i++;
	}
	return 0;
}

/***********Swap********************/
void Swap(int x,int y)
{
	int t;
	t=x;
	x=y;
	y=t;
	printf("After Swap:a=%d b=%d\n\n",x,y);
}
